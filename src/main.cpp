#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include "ManejadorDelPrograma.hpp"
#include "estrategias-ci/ServidorCIStrategy.hpp"
#include "estrategias-ci/TravisStrategy.hpp"
#include "estrategias-ci/CircleCIStrategy.hpp"

ManejadorDelPrograma manejadorDelPrograma;
WebServer webServer(80);

const char* ssid = "Fibertel WiFi304 2.4GHz";
const char* password = "0141695284";

void actualizacionDeWiFiRequest() {  
    if (!webServer.hasArg("plain")) { 
        webServer.send(200);
        return;
    }
 
    String jsonBody = webServer.arg("plain");
    Serial.println("Original: ");
    Serial.println(jsonBody);
 
    DynamicJsonDocument dynamicJsonDocument(1024);
    deserializeJson(dynamicJsonDocument, jsonBody);   
    JsonObject jsonObject = dynamicJsonDocument.as<JsonObject>();
    const char* redNueva = jsonObject["username"];
    const char* contrasenaNueva = jsonObject["password"];

    webServer.sendHeader("Access-Control-Allow-Origin", "*");
    webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
    webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    webServer.send(200);

    manejadorDelPrograma.establecerConexionWiFi(redNueva, contrasenaNueva);
}

void actualizacionDeServidorRequest() {
    if (!webServer.hasArg("plain")) { 
        webServer.send(200);
        return;
    }
 
    String jsonBody = webServer.arg("plain");
    Serial.println("Original: ");
    Serial.println(jsonBody);
 
    DynamicJsonDocument dynamicJsonDocument(1024);
    deserializeJson(dynamicJsonDocument, jsonBody);   
    JsonObject jsonObject = dynamicJsonDocument.as<JsonObject>();
    
    String servidorCIN = jsonObject["servidorCI"];
    String tokenAccesoN = jsonObject["tokenAcceso"];
    String repositorioIdN = jsonObject["repositorioId"];

    if(servidorCIN == "TravisCI") { 
        TravisStrategy *travisStrategy = new TravisStrategy();
        travisStrategy->definirTokenAcceso(tokenAccesoN);
        travisStrategy->definirRepositorioId(repositorioIdN);
        manejadorDelPrograma.definirServidorDeIntegracionContinua(travisStrategy);
    } else if(servidorCIN == "CircleCI") {
        CircleCIStrategy *circleCIStrategy = new CircleCIStrategy();
        circleCIStrategy->definirTokenAcceso(tokenAccesoN);
        circleCIStrategy->definirRepositorioId(repositorioIdN);
        manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);
    }

    webServer.sendHeader("Access-Control-Allow-Origin", "*");
    webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
    webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    webServer.send(200);
}

void setup() {
    Serial.begin(115200);
    
    WiFi.mode(WIFI_STA);

    manejadorDelPrograma.establecerConexionWiFi(ssid, password);

    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("esp32")) {
        Serial.println("MDNS responder started");
    }

    webServer.on("/", HTTP_OPTIONS, []() {
        webServer.sendHeader("Access-Control-Max-Age", "10000");
        webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
        webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
        webServer.send(200, "text/plain", "");
    });

    webServer.on("/wifi", HTTP_POST, actualizacionDeWiFiRequest);
    webServer.on("/servidor", HTTP_POST, actualizacionDeServidorRequest);
    webServer.begin();
    
    Serial.println("HTTP server started");

    //Por defecto podemos definir CircleCI
    CircleCIStrategy *circleCIStrategy = new CircleCIStrategy();
    const char* tokenAcceso1 = "8761a13e3eb7b85dd360b5b7b85bd63c9f8841bf";
    circleCIStrategy->definirTokenAcceso(tokenAcceso1);
    const char* repositorioId1 = "sample-repository";
    circleCIStrategy->definirRepositorioId(repositorioId1);
    manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);
}

void loop() {
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    webServer.handleClient();
}
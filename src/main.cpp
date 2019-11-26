#ifndef UNIT_TEST 

#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

#include "ControladorDeWifi.h"
#include "ControladorDeLeds.h"
#include "ManejadorDelPrograma.h"
#include "ServidorCIStrategy.h"
#include "TravisCIStrategy.h"
#include "CircleCIStrategy.h"

WebServer webServer(80);
ControladorDeWifi *controladorDeWifi = new ControladorDeWifi();
ControladorDeLeds *controladorDeLeds = new ControladorDeLeds();
ManejadorDelPrograma manejadorDelPrograma(controladorDeWifi, controladorDeLeds);

void inicializarApi();
void pingRequest();
void actualizacionDeWiFiRequest();
void actualizacionDeServidorRequest();

void setup() {
    Serial.begin(115200);
    
    //Inicializamos la conexión WiFi
    const char* nombreRed = "wifi18878";
    const char* contrasenaRed = "51883488";
    manejadorDelPrograma.establecerConexionWiFi(nombreRed, contrasenaRed);

    //Inicializamos la api de configuración
    inicializarApi();

    //Por defecto podemos definir CircleCI
    CircleCIStrategy *circleCIStrategy = new CircleCIStrategy("8761a13e3eb7b85dd360b5b7b85bd63c9f8841bf", "sample-repository");
    manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);
}

void loop() {
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    webServer.handleClient();
}

void inicializarApi() {
    MDNS.begin("esp32");

    webServer.on("/", HTTP_OPTIONS, []() {
        webServer.sendHeader("Access-Control-Max-Age", "10000");
        webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
        webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
        webServer.send(200, "text/plain", "");
    });

    webServer.on("/ping", HTTP_GET, pingRequest);
    webServer.on("/wifi", HTTP_POST, actualizacionDeWiFiRequest);
    webServer.on("/servidor", HTTP_POST, actualizacionDeServidorRequest);
    webServer.begin();
}

void pingRequest() {  
    webServer.sendHeader("Access-Control-Allow-Origin", "*");
    webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
    webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    webServer.send(200, "text/plain", "pong");
}

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
    webServer.send(200, "text/plain", "");

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
    
    String servidorCINuevo = jsonObject["servidorCI"];
    String tokenAccesoNuevo = jsonObject["tokenAcceso"];
    String identificadorDelRepositorioNuevo = jsonObject["identificadorDelRepositorio"];

    if(servidorCINuevo == "TravisCI") { 
        TravisCIStrategy *travisCIStrategy = new TravisCIStrategy(tokenAccesoNuevo, identificadorDelRepositorioNuevo);
        manejadorDelPrograma.definirServidorDeIntegracionContinua(travisCIStrategy);
    } else if(servidorCINuevo == "CircleCI") {
        CircleCIStrategy *circleCIStrategy = new CircleCIStrategy(tokenAccesoNuevo, identificadorDelRepositorioNuevo);
        manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);
    }

    webServer.sendHeader("Access-Control-Allow-Origin", "*");
    webServer.sendHeader("Access-Control-Allow-Methods", "POST,GET,OPTIONS");
    webServer.sendHeader("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    webServer.send(200, "text/plain", "");
}
#endif
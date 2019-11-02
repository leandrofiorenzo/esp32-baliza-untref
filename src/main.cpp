#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

ManejadorDelPrograma manejadorDelPrograma;

String estado = "";

void setup () {

    Serial.begin(115200);

}

void loop () {

    manejadorDelPrograma.definirEstrategia(1);

    estado = manejadorDelPrograma.obtenerEstadoUltimoBuild();

    Serial.println(estado);

    delay(1000);

    manejadorDelPrograma.definirEstrategia(2);

    estado = manejadorDelPrograma.obtenerEstadoUltimoBuild();

    Serial.println(estado);

    delay(1000);
}

/*#include <ArduinoJson.h>

#include <WiFi.h>
#include <WiFiMulti.h>

#include <HTTPClient.h>

#define USE_SERIAL Serial

WiFiMulti wifiMulti;

//#include "BuildResult.h"
//#include "WorkerRename.h"
//WorkerRename workerRename;

int pinWifi = 2;
int pinCreated = 23;
int pinStarted = 22;
int pinFailed = 19;
int pinPassed = 21;
int pinNoState = 18;

void setup() {
  
  USE_SERIAL.begin(115200);
  
  pinMode(pinWifi, OUTPUT);
  pinMode(pinCreated, OUTPUT);
  pinMode(pinStarted, OUTPUT);
  pinMode(pinFailed, OUTPUT);
  pinMode(pinPassed, OUTPUT);
  pinMode(pinNoState, OUTPUT); 
  
  USE_SERIAL.println();
  USE_SERIAL.println();
  USE_SERIAL.println();

  for(uint8_t t = 4; t > 0; t--) {
      USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
      USE_SERIAL.flush();
      delay(1000);
  }

  wifiMulti.addAP("Fibertel WiFi NUMERO 2", "00416040571");

}

void loop() {
     
    // wait for WiFi connection
    if((wifiMulti.run() == WL_CONNECTED)) {
        digitalWrite(pinWifi, HIGH);

        HTTPClient http;

        USE_SERIAL.print("[HTTP] begin...\n");
        http.begin("https://api.travis-ci.org/builds?limit=1");
        http.addHeader("Authorization", "token zxiel_jS6Xaaok3zgnHGzQ"); 
        http.addHeader("Travis-API-Version", "3"); 

        USE_SERIAL.print("[HTTP] GET...\n");
        int httpCode = http.GET();

        if(httpCode > 0) {
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            if(httpCode == HTTP_CODE_OK) {
                String jsonResponse = http.getString(); 

                DynamicJsonDocument dynamicJsonDocument(1024);
                deserializeJson(dynamicJsonDocument, jsonResponse);   
                JsonObject jsonObject = dynamicJsonDocument.as<JsonObject>();
                int id = jsonObject["builds"][0]["id"];
                String state = jsonObject["builds"][0]["state"];

                USE_SERIAL.println(id);
                USE_SERIAL.println(state);
                USE_SERIAL.println("------");
       
                if(state == "created") {
                    digitalWrite(pinCreated, HIGH);
                    digitalWrite(pinStarted, LOW);
                    digitalWrite(pinFailed, LOW);
                    digitalWrite(pinPassed, LOW);
                    digitalWrite(pinNoState, LOW);                  
                } else if(state == "started") {
                    digitalWrite(pinCreated, LOW);
                    digitalWrite(pinStarted, HIGH);
                    digitalWrite(pinFailed, LOW);
                    digitalWrite(pinPassed, LOW);
                    digitalWrite(pinNoState, LOW);    
                } else if(state == "failed") {
                    digitalWrite(pinCreated, LOW);
                    digitalWrite(pinStarted, LOW);
                    digitalWrite(pinFailed, HIGH);
                    digitalWrite(pinPassed, LOW);
                    digitalWrite(pinNoState, LOW);
                } else if(state == "passed") {
                    digitalWrite(pinCreated, LOW);
                    digitalWrite(pinStarted, LOW);
                    digitalWrite(pinFailed, LOW);
                    digitalWrite(pinPassed, HIGH);
                    digitalWrite(pinNoState, LOW);
                } else {
                    digitalWrite(pinCreated, LOW);
                    digitalWrite(pinStarted, LOW);
                    digitalWrite(pinFailed, LOW);
                    digitalWrite(pinPassed, LOW);
                    digitalWrite(pinNoState, HIGH);
                }
                
            } else {
              digitalWrite(pinNoState, HIGH);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  
        }

        http.end();
        delay(3000);
        
    } else {
      USE_SERIAL.print("No se pudo conectar. Reintentando...\n");
      digitalWrite(pinWifi, LOW);
      delay(3000);
    }   
}
*/
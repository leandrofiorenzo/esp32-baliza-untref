#include <ArduinoJson.h>
#include <Arduino.h>
#include "TravisStrategy.hpp"

TravisStrategy::TravisStrategy() {

};

String TravisStrategy::obtenerEstadoUltimoBuild() {
    HTTPClient clienteHttp;

    String estadoBuild = "no-state";

    clienteHttp.begin("https://api.travis-ci.org/builds?limit=1");
    clienteHttp.addHeader("Authorization", "token zxiel_jS6Xaaok3zgnHGzQ"); 
    clienteHttp.addHeader("Travis-API-Version", "3"); 

    int httpCode = clienteHttp.GET();
    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            String jsonResponse = clienteHttp.getString(); 

            DynamicJsonDocument dynamicJsonDocument(1024);
            deserializeJson(dynamicJsonDocument, jsonResponse);   
            JsonObject jsonObject = dynamicJsonDocument.as<JsonObject>();
            return jsonObject["builds"][0]["state"];

            /*if(state == "created") {
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
            }*/
            
        } else {
            Serial.print("Fallo. Estado: ");
            Serial.println(httpCode);            
            //digitalWrite(pinNoState, HIGH);
        }
    } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", clienteHttp.errorToString(httpCode).c_str());
    }

    clienteHttp.end();

    return estadoBuild;
};


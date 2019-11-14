#include <ArduinoJson.h>
#include <Arduino.h>
#include "TravisStrategy.hpp"
#include "enums/EstadoBuildEnum.hpp"

TravisStrategy::TravisStrategy() {

};

EstadoBuildEnum TravisStrategy::obtenerEstadoUltimoBuild() {
    HTTPClient clienteHttp;

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
            String estadoBuildString = jsonObject["builds"][0]["state"];

            if(estadoBuildString == "created") {            
                return EstadoBuildEnum::Creado;               
            } else if(estadoBuildString == "started") {
                return EstadoBuildEnum::EnCurso;    
            } else if(estadoBuildString == "failed") {
                return EstadoBuildEnum::Fallido;
            } else if(estadoBuildString == "passed") {
                return EstadoBuildEnum::Exitoso;
            } else {
                return EstadoBuildEnum::Desconexion;
            }
        } else {
            Serial.print("El request devolvio el status code: ");
            Serial.println(httpCode);           
            return EstadoBuildEnum::Desconocido;
        }
    } else {
        Serial.printf("El request devolvio el status code: %s\n", clienteHttp.errorToString(httpCode).c_str());
    }

    clienteHttp.end();

    return EstadoBuildEnum::Desconocido;
};


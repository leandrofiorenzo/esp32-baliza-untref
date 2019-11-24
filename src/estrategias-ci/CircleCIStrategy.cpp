#include "CircleCIStrategy.h"

CircleCIStrategy::CircleCIStrategy() {

};

CircleCIStrategy::~CircleCIStrategy() {

};

EstadoBuildEnum CircleCIStrategy::obtenerEstadoUltimoBuild() {
    Serial.println("Soy CircleCI");
    HTTPClient clienteHttp;

    String url = "https://circleci.com/api/v1.1/project/github/leandrofiorenzo/" + repositorioId + "?circle-token=" + tokenAcceso + "&limit=1";
    
    clienteHttp.begin(url);
    clienteHttp.addHeader("Accept", "application/json"); 

    int httpCode = clienteHttp.GET();
    if(httpCode > 0) {
        if(httpCode == HTTP_CODE_OK) {
            String jsonResponse = clienteHttp.getString(); 

            const size_t capacity = 4 * JSON_ARRAY_SIZE(0) + 
                2 * JSON_ARRAY_SIZE(1) + 
                JSON_OBJECT_SIZE(0) + 
                JSON_OBJECT_SIZE(1) + 
                JSON_OBJECT_SIZE(3) + 
                JSON_OBJECT_SIZE(6) +
                JSON_OBJECT_SIZE(7) +
                JSON_OBJECT_SIZE(13) +
                JSON_OBJECT_SIZE(57) + 
                2220;

            DynamicJsonDocument dynamicJsonDocument(capacity);
            deserializeJson(dynamicJsonDocument, jsonResponse);
            JsonObject jsonObject = dynamicJsonDocument[0];
            String estadoBuildString = jsonObject["status"];       
  
            if(estadoBuildString == "queued") {            
                return EstadoBuildEnum::EnCurso;               
            } else if(estadoBuildString == "running") {
                return EstadoBuildEnum::EnCurso;    
            } else if(estadoBuildString == "failed") {
                return EstadoBuildEnum::Fallido;
            } else if(estadoBuildString == "success") {
                return EstadoBuildEnum::Exitoso;
            } else {
                return EstadoBuildEnum::Desconocido;
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

void CircleCIStrategy::definirTokenAcceso(String _tokenAccesso) {
    tokenAcceso = _tokenAccesso;
};

void CircleCIStrategy::definirRepositorioId(String _repositorioId) {
    repositorioId = _repositorioId;
};

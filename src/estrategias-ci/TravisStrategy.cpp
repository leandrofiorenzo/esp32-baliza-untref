
#include "TravisStrategy.h"

TravisStrategy::TravisStrategy() {

};

TravisStrategy::~TravisStrategy() {

};

EstadoBuildEnum TravisStrategy::obtenerEstadoUltimoBuild() {
    Serial.println("Soy TravisCI");
    HTTPClient clienteHttp;

    String url = "https://api.travis-ci.org/repo/" + repositorioId + "/builds?limit=1";
    String token = "token " + tokenAcceso;

    clienteHttp.begin(url);
    clienteHttp.addHeader("Authorization", token); 
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
                return EstadoBuildEnum::EnCurso;               
            } else if(estadoBuildString == "started") {
                return EstadoBuildEnum::EnCurso;    
            } else if(estadoBuildString == "failed") {
                return EstadoBuildEnum::Fallido;
            } else if(estadoBuildString == "passed") {
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

void TravisStrategy::definirTokenAcceso(String _tokenAccesso) {
    tokenAcceso = _tokenAccesso;
};

void TravisStrategy::definirRepositorioId(String _repositorioId) {
    repositorioId = _repositorioId;
};
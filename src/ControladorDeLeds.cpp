#include <Arduino.h>
#include "ControladorDeLeds.hpp"

void ControladorDeLeds::prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild) {
    if(estadoBuild == EstadoBuildEnum::Creado) {
        Serial.println("Estoy Creado");
    } else if(estadoBuild == EstadoBuildEnum::Desconocido) {
        Serial.println("Estoy Desconocido");
    } else if(estadoBuild == EstadoBuildEnum::EnCurso) {
        Serial.println("Estoy EnCurso");   
    } else if(estadoBuild == EstadoBuildEnum::Exitoso) {
        Serial.println("Estoy Exitoso");   
    } else if(estadoBuild == EstadoBuildEnum::Fallido) {
        Serial.println("Estoy Fallido");   
    } else {
        Serial.println("Estoy nn");
    }
};
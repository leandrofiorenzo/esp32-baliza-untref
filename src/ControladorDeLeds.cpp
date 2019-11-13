#include <Arduino.h>
#include "ControladorDeLeds.hpp"


void ControladorDeLeds::prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild) {
    if(estadoBuild == EstadoBuildEnum::Creado) {
        Serial.println("Estoy Creado");
    } /*else if(estadoBuild == EstadoBuildEnum::Desconocido) {*/
    else if(estadoBuild == EstadoBuildEnum::Desconexion) {
        Serial.println("Estoy Desconectado de WiFi");
    } else if(estadoBuild == EstadoBuildEnum::EnCurso) {
        digitalWrite(17, HIGH);
        Serial.println("Estoy EnCurso");   
    } else if(estadoBuild == EstadoBuildEnum::Exitoso) {
        digitalWrite(18, HIGH);
        digitalWrite(17, LOW);
        Serial.println("Estoy Exitoso");   
    } else if(estadoBuild == EstadoBuildEnum::Fallido) {
        digitalWrite(19, HIGH);
        digitalWrite(17, LOW);
        Serial.println("Estoy Fallido");   
    } else {
        Serial.println("Estoy nn");
    }
};

void ControladorDeLeds::iniciarAnalisisBuild(){
    digitalWrite(17, LOW);
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    prenderLedCorrespondienteAlEstado(EnCurso);
}
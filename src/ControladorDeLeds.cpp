#include <Arduino.h>
#include "ControladorDeLeds.hpp"

ControladorDeLeds::ControladorDeLeds() {
    pinMode(15, OUTPUT);
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(21, OUTPUT); 
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
}

void ControladorDeLeds::prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild) {
    apagarTodosLosLeds();
    if(estadoBuild == EstadoBuildEnum::Creado) {
        Serial.println("Estoy Creado");
        digitalWrite(18, HIGH);
    } else if(estadoBuild == EstadoBuildEnum::Desconexion) {
        Serial.println("Estoy Desconectado de WiFi");
        digitalWrite(19, HIGH);
    } else if(estadoBuild == EstadoBuildEnum::EnCurso) {
        digitalWrite(21, HIGH);
        Serial.println("Estoy EnCurso");   
    } else if(estadoBuild == EstadoBuildEnum::Exitoso) {
        digitalWrite(22, HIGH);
        Serial.println("Estoy Exitoso");   
    } else if(estadoBuild == EstadoBuildEnum::Fallido) {
        digitalWrite(23, HIGH);
        Serial.println("Estoy Fallido");   
    } else {
        digitalWrite(15, HIGH);
        Serial.println("Estoy Desconocido");
    }
};

void ControladorDeLeds::configurarPaletaColoresLed(int ledRojo, int ledAzul, int ledVerde){
    digitalWrite(23, ledRojo);
    digitalWrite(22, ledVerde);
    digitalWrite(19, ledAzul);
};

void ControladorDeLeds::apagarTodosLosLeds() {
    digitalWrite(18, LOW);
    digitalWrite(19, LOW);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    digitalWrite(15, LOW);
};


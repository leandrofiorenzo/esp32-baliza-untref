#include <Arduino.h>
#include "ControladorDeLeds.h"

ControladorDeLeds::ControladorDeLeds() {
    pinMode(18, OUTPUT);
    pinMode(19, OUTPUT);
    pinMode(21, OUTPUT); 
    pinMode(22, OUTPUT);
    pinMode(23, OUTPUT);
    //pinMode(34, OUTPUT);
    //pinMode(35, OUTPUT);
}

void ControladorDeLeds::prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum estadoConexion) {
    if(estadoConexion == EstadoBuildEnum::ConectadoWIFI) {
        Serial.println("Estoy Conectado a WiFi");
        //digitalWrite(19, HIGH);
        configurarPaletaColoresLedEstadoConexion(19,18);
    } else if(estadoConexion == EstadoBuildEnum::DesconexionWIFI) {
        Serial.println("Estoy Desconectado de WiFi");
        //digitalWrite(19, HIGH);
        configurarPaletaColoresLedEstadoConexion(18,19);
    }
}

void ControladorDeLeds::prenderLedCorrespondienteAlEstado(EstadoBuildEnum estadoBuild) {
    apagarTodosLosLeds();
    if(estadoBuild == EstadoBuildEnum::Creado) {
        Serial.println("Estoy Creado");
        digitalWrite(18, HIGH);
    } else if(estadoBuild == EstadoBuildEnum::EnCurso) {
        //digitalWrite(21, HIGH);
        Serial.println("Estoy EnCurso");
        configurarPaletaColoresLedEstadoBuild(LOW, LOW, HIGH);
        delay(200);
        configurarPaletaColoresLedEstadoBuild(LOW, LOW, LOW);
        delay(200);
        configurarPaletaColoresLedEstadoBuild(LOW, LOW, HIGH);
        /*configurarPaletaColoresLedEstadoBuild(HIGH, 15, 0);
        delay(200);
        configurarPaletaColoresLedEstadoBuild(LOW, LOW, LOW);
        delay(200);
        configurarPaletaColoresLedEstadoBuild(HIGH, 15, 0); */
    } else if(estadoBuild == EstadoBuildEnum::Exitoso) {
        //digitalWrite(22, HIGH);
        Serial.println("Exitoso");   
        configurarPaletaColoresLedEstadoBuild(LOW, HIGH, LOW);
    } else if(estadoBuild == EstadoBuildEnum::Fallido) {
        //digitalWrite(23, HIGH);
        Serial.println("Estoy Fallido");   
        configurarPaletaColoresLedEstadoBuild(HIGH, LOW, LOW);
    } else {
        //digitalWrite(15, HIGH);
        configurarPaletaColoresLedEstadoBuild(HIGH, HIGH, HIGH); // Blanco
        Serial.println("Estoy Desconocido");
    }
};

void ControladorDeLeds::configurarPaletaColoresLedEstadoBuild(uint8_t ledRojo, uint8_t ledVerde, uint8_t ledAzul) {
    digitalWrite(23, ledRojo);
    digitalWrite(22, ledVerde);
    digitalWrite(21, ledAzul);
};

void ControladorDeLeds::configurarPaletaColoresLedEstadoConexion(int pinEncendido,int pinApagado){
    digitalWrite(pinEncendido, HIGH);
    digitalWrite(pinApagado, LOW);
}

void ControladorDeLeds::apagarTodosLosLeds() {
    //digitalWrite(18, LOW);
    //digitalWrite(19, LOW);
    digitalWrite(21, LOW);
    digitalWrite(22, LOW);
    digitalWrite(23, LOW);
    //digitalWrite(15, LOW);
};


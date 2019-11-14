#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

ManejadorDelPrograma manejadorDelPrograma;

String estadoBuild = "";

void setup () {

    Serial.begin(115200);

    manejadorDelPrograma.establecerConexionWiFi("LAPTOP-VNJ3NAQE 9679", "lfiorenzo123");

    manejadorDelPrograma.definirServidorDeIntegracionContinua(1);
    
}

void loop () {

    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    Serial.println(estadoBuild);

    delay(3000);
}
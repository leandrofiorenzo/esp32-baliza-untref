#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

ManejadorDelPrograma manejadorDelPrograma;

String estadoBuild = "";

void setup () {

    Serial.begin(115200);

    manejadorDelPrograma.establecerConexionWiFi("LAPTOP-VNJ3NAQE 9679", "lfiorenzo123");
    
}

void loop () {

    manejadorDelPrograma.definirServidorDeIntegracionContinua(1);

    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    Serial.println(estadoBuild);

    delay(3000);

    manejadorDelPrograma.definirServidorDeIntegracionContinua(2);

    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    Serial.println(estadoBuild);

    delay(3000);
}
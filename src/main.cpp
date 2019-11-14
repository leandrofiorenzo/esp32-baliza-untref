#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"

#include "estrategias-integracion-continua/StrategyFicticia.hpp"

ManejadorDelPrograma manejadorDelPrograma;

String estadoBuild = "";

void setup () {

    Serial.begin(115200);

    const char* ssid = "LAPTOP-VNJ3NAQE 9679";
    const char* password = "lfiorenzo123";
    manejadorDelPrograma.establecerConexionWiFi(ssid, password);
    
}

void loop () {

    //manejadorDelPrograma.definirServidorDeIntegracionContinua(new TravisStrategy());

    //manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    //delay(1000);

    manejadorDelPrograma.definirServidorDeIntegracionContinua(new StrategyFicticia());

    manejadorDelPrograma.ejecutarRutinaDeVerificacion();

    delay(100);
}
#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/StrategyFicticia.hpp"

ManejadorDelPrograma manejadorDelPrograma;

void setup () {
    Serial.begin(115200);
    const char* ssid = "Fibertel WiFi NUMERO 2";
    const char* passphrase = "00416040571";
    manejadorDelPrograma.establecerConexionWiFi(ssid, passphrase);  
}

void loop () {
    manejadorDelPrograma.definirServidorDeIntegracionContinua(new TravisStrategy());
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();
    delay(1000);
}
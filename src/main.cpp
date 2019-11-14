#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/StrategyFicticia.hpp"

ManejadorDelPrograma manejadorDelPrograma;

void setup () {
    Serial.begin(115200);
    const char* ssid = "Redmi";
    const char* passphrase = "lfiorenzo123";
    manejadorDelPrograma.establecerConexionWiFi(ssid, passphrase);  
}

void loop () {
    manejadorDelPrograma.definirServidorDeIntegracionContinua(new TravisStrategy());
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();
    delay(1000);
}
#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/StrategyFicticia.hpp"

ManejadorDelPrograma manejadorDelPrograma;

#include "BluetoothSerial.h"

void setup () {
    Serial.begin(115200);
    const char* ssid = "Fibertel WiFi NUMERO 2";
    const char* passphrase = "00416040571";
    manejadorDelPrograma.establecerConexionWiFi(ssid, passphrase);
}

void loop () {
    TravisStrategy *travisStrategy = new TravisStrategy();

    const char* tokenAccesso = "zxiel_jS6Xaaok3zgnHGzQ";
    travisStrategy->definirTokenAcceso(tokenAccesso);
    
    const char* repositorioId = "26796622";
    travisStrategy->definirRepositorioId(repositorioId);

    manejadorDelPrograma.definirServidorDeIntegracionContinua(travisStrategy);
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();
}
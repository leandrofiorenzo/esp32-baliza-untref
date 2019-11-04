#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"
#include "./ci/TravisStrategy.hpp"
#include "./ci/StrategyFicticia.hpp"

ManejadorDelPrograma::ManejadorDelPrograma() {

};

String ManejadorDelPrograma::obtenerEstadoUltimoBuild() {
    if(controladorWifi.estaConectado()) {
        return servidorIntegracionContinuaStrategy->obtenerEstadoUltimoBuild();
    } else {
        Serial.println("No hay conexión. Reintentando...");
    }
};

void ManejadorDelPrograma::definirEstrategia(int ci) {
    if(ci == 1) {
        servidorIntegracionContinuaStrategy = new TravisStrategy();
    } else {
        servidorIntegracionContinuaStrategy = new StrategyFicticia();
    }
};

void ManejadorDelPrograma::establecerConexionWiFi(char *ssid, char *passphrase) {
    controladorWifi.establecerConexionWiFi(ssid, passphrase);
}
#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"
#include "ci/TravisStrategy.hpp"
#include "ci/StrategyFicticia.hpp"
#include "enums/EstadoBuildEnum.hpp"

ManejadorDelPrograma::ManejadorDelPrograma() {

};

String ManejadorDelPrograma::ejecutarRutina() {
    if(controladorWifi.estaConectado()) {
        //1) Obtenemos el estado del ultimo build en el CI que corresponda.
        EstadoBuildEnum estadoBuild = servidorDeIntegracionContinuaStrategy->obtenerEstadoUltimoBuild();

        
    } else {
        Serial.println("No hay conexión. Reintentando...");
    }
};

void ManejadorDelPrograma::definirServidorDeIntegracionContinua(int ci) {
    if(ci == 1) {
        servidorDeIntegracionContinuaStrategy = new TravisStrategy();
    } else {
        servidorDeIntegracionContinuaStrategy = new StrategyFicticia();
    }
};

void ManejadorDelPrograma::establecerConexionWiFi(char *ssid, char *passphrase) {
    controladorWifi.establecerConexionWiFi(ssid, passphrase);
}
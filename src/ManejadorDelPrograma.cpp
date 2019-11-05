#include <Arduino.h>
#include "ManejadorDelPrograma.hpp"
#include "ci/TravisStrategy.hpp"
#include "ci/StrategyFicticia.hpp"
#include "enums/EstadoBuildEnum.hpp"

ManejadorDelPrograma::ManejadorDelPrograma() {

};

void ManejadorDelPrograma::ejecutarRutinaDeVerificacion() {
    if(controladorDeWifi.estaConectado()) {
        //1) Obtenemos el estado del ultimo build en el CI que corresponda.
        EstadoBuildEnum estadoBuild = servidorDeIntegracionContinuaStrategy->obtenerEstadoUltimoBuild();  

        //2) Prendemos el led que corresponda.
        controladorDeLeds.prenderLedCorrespondienteAlEstado(estadoBuild);
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
    controladorDeWifi.establecerConexionWiFi(ssid, passphrase);
}
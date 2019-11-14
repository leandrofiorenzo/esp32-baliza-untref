#include <Arduino.h>
#include "ManejadorDelPrograma.hpp"
#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/StrategyFicticia.hpp"
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
        controladorDeLeds.prenderLedCorrespondienteAlEstado(EstadoBuildEnum::Desconexion);
    }
};

void ManejadorDelPrograma::definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *asd) {  
    delete servidorDeIntegracionContinuaStrategy;
    servidorDeIntegracionContinuaStrategy = asd;    
    /*if(ci == 1) {
        servidorDeIntegracionContinuaStrategy = new TravisStrategy();
    } else {
        servidorDeIntegracionContinuaStrategy = new StrategyFicticia();
    }*/
};

void ManejadorDelPrograma::establecerConexionWiFi(const char *ssid, const char *passphrase) {
    controladorDeWifi.establecerConexionWiFi(ssid, passphrase);
}
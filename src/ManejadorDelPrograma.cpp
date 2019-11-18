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
 
    }  else {
        Serial.println("No hay conexión. Reintentando...");
        controladorDeLeds.prenderLedCorrespondienteAlEstado(EstadoBuildEnum::Desconexion);
        controladorDeWifi.establecerConexionWiFi();
    }      
};

void ManejadorDelPrograma::definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *servidorCI) {  
    delete servidorDeIntegracionContinuaStrategy;
    servidorDeIntegracionContinuaStrategy = servidorCI;    
};

void ManejadorDelPrograma::establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed) {
    controladorDeWifi.cambiarCredencialesConexion(nombreRed, contrasenaRed);
};
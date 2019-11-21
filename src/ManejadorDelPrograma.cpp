#include <Arduino.h>
#include "ManejadorDelPrograma.hpp"
#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/CircleCIStrategy.hpp"
#include "enums/EstadoBuildEnum.hpp"

ManejadorDelPrograma::ManejadorDelPrograma() {

};

void ManejadorDelPrograma::ejecutarRutinaDeVerificacion() {  
    

    if(controladorDeWifi.estaConectado()) {    

        controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::ConectadoWIFI);

        //1) Obtenemos el estado del ultimo build en el CI que corresponda.
        EstadoBuildEnum estadoBuild = servidorDeIntegracionContinuaStrategy->obtenerEstadoUltimoBuild();  
        
        //2) Prendemos el led que corresponda.
        controladorDeLeds.prenderLedCorrespondienteAlEstado(estadoBuild);

    }  else {
        Serial.println("No hay conexión. Reintentando...");
        controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::DesconexionWIFI);
        controladorDeWifi.establecerConexionWiFi();
    }      
};

void ManejadorDelPrograma::ejecutarRutinaDeVerificacionesDeNovedades() {
    String novedadTipo = controladorDeBluetooth.obtenerTipoDeNovedad();
    if(novedadTipo == "WIFI") {
        establecerConexionWiFi(controladorDeBluetooth.obtenerNombreRed(), controladorDeBluetooth.obtenerContrasenaRed());
    } 
}

void ManejadorDelPrograma::definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *servidorCI) {  
    delete servidorDeIntegracionContinuaStrategy;
    servidorDeIntegracionContinuaStrategy = servidorCI;    
};

void ManejadorDelPrograma::establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed) {
    controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::DesconexionWIFI);
    controladorDeWifi.cambiarCredencialesConexion(nombreRed, contrasenaRed);
};
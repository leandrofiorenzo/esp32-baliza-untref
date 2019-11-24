#include "ManejadorDelPrograma.h"

ManejadorDelPrograma::ManejadorDelPrograma(ControladorDeWifi *_controladorDeWifi) {
    controladorDeWifi = _controladorDeWifi;
};

void ManejadorDelPrograma::ejecutarRutinaDeVerificacion() {  
    if(controladorDeWifi->estaConectado()) {    

        controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::ConectadoWIFI);

        //1) Obtenemos el estado del ultimo build en el CI que corresponda.
        EstadoBuildEnum estadoBuild = servidorCI->obtenerEstadoUltimoBuild();  
        
        //2) Prendemos el led que corresponda.
        controladorDeLeds.prenderLedCorrespondienteAlEstado(estadoBuild);

    }  else {
        Serial.println("No hay conexión. Reintentando...");
        controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::DesconexionWIFI);
        controladorDeWifi->establecerConexionWiFi();
    }      
};

void ManejadorDelPrograma::definirServidorDeIntegracionContinua(ServidorCIStrategy *_servidorCI) {  
    delete servidorCI;
    servidorCI = _servidorCI;    
};

void ManejadorDelPrograma::establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed) {
    controladorDeLeds.prenderLedCorrespondienteAlEstadoConexion(EstadoBuildEnum::DesconexionWIFI);
    controladorDeWifi->cambiarCredencialesConexion(nombreRed, contrasenaRed);
};

int ManejadorDelPrograma::dameNumero() {
    return 3;
}
#include <Arduino.h>
#include "ServidorCIStrategy.h"
#include "ControladorDeWifi.h"
#include "ControladorDeLeds.h"
#include "EstadoBuildEnum.h"

class ManejadorDelPrograma {
    private:
        ServidorCIStrategy *servidorCI;
        ControladorDeWifi *controladorDeWifi;
        ControladorDeLeds *controladorDeLeds;
    public: 
        ManejadorDelPrograma(ControladorDeWifi *_controladorDeWifi, ControladorDeLeds *_controladorDeLeds);
        void ejecutarRutinaDeVerificacion();
        void definirServidorDeIntegracionContinua(ServidorCIStrategy *_servidorCI);
        void establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed);
        int dameNumero();
};
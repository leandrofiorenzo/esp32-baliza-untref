#include "estrategias-integracion-continua/ServidorIntegracionContinuaStrategy.hpp"
#include "ControladorDeWifi.hpp"
#include "ControladorDeLeds.hpp"
#include "ControladorDeBluetooth.hpp"

class ManejadorDelPrograma {
    private:
        ServidorIntegracionContinuaStrategy *servidorDeIntegracionContinuaStrategy;
        ControladorDeWifi controladorDeWifi;
        ControladorDeLeds controladorDeLeds;
        ControladorDeBluetooth controladorDeBluetooth;
    public: 
        ManejadorDelPrograma();
        void ejecutarRutinaDeVerificacion();
        void ejecutarRutinaDeVerificacionesDeNovedades();
        void definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *servidorCI);
        void establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed);
};
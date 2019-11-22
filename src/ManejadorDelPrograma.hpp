#include "estrategias-integracion-continua/ServidorIntegracionContinuaStrategy.hpp"
#include "ControladorDeWifi.hpp"
#include "ControladorDeLeds.hpp"

class ManejadorDelPrograma {
    private:
        ServidorIntegracionContinuaStrategy *servidorDeIntegracionContinuaStrategy;
        ControladorDeWifi controladorDeWifi;
        ControladorDeLeds controladorDeLeds;
    public: 
        ManejadorDelPrograma();
        void ejecutarRutinaDeVerificacion();
        void definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *servidorCI);
        void establecerConexionWiFi(const char *nombreRed, const char *contrasenaRed);
};
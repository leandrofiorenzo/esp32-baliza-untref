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
        void definirServidorDeIntegracionContinua(ServidorIntegracionContinuaStrategy *asd);
        void establecerConexionWiFi(const char *ssid, const char *passphrase);
};
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
        void definirServidorDeIntegracionContinua(int ci);
        void establecerConexionWiFi(char *ssid, char *passphrase);
};
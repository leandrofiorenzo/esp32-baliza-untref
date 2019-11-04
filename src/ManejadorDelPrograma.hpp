#include "./ci/ServidorIntegracionContinuaStrategy.hpp"
#include "ControladorWifi.hpp"

class ManejadorDelPrograma {
    private:
        ServidorIntegracionContinuaStrategy *servidorDeIntegracionContinuaStrategy;
        ControladorWifi controladorWifi;
    public: 
        ManejadorDelPrograma();
        String ejecutarRutina();
        void definirServidorDeIntegracionContinua(int ci);
        void establecerConexionWiFi(char *ssid, char *passphrase);
};
#include "./ci/ServidorIntegracionContinuaStrategy.hpp"
#include "ControladorWifi.hpp"

class ManejadorDelPrograma {
    private:
        ServidorIntegracionContinuaStrategy *servidorIntegracionContinuaStrategy;
        ControladorWifi controladorWifi;
    public: 
        ManejadorDelPrograma();
        String obtenerEstadoUltimoBuild();
        void definirEstrategia(int ci);
        void establecerConexion(char *ssid, char *passowrd);
};
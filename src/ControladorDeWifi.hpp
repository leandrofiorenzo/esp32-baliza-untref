#include <WiFi.h>

class ControladorDeWifi {
    public:
        ControladorDeWifi();
        void establecerConexionWiFi(char *ssid, char *passphrase);      
        boolean estaConectado();
        const char* obtenerEstadoDeLaConexion(wl_status_t status);
};
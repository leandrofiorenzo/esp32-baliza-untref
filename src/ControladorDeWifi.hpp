#include <WiFi.h>

class ControladorDeWifi {
    public:
        ControladorDeWifi();
        void establecerConexionWiFi(const char *ssid, const char *passphrase);      
        boolean estaConectado();
        const char* obtenerEstadoDeLaConexion(wl_status_t status);
};
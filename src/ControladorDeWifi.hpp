#include <WiFi.h>

class ControladorDeWifi {
    private:
        const char* nombreRed = ""; 
        const char* contraseñaRed = "";
    public:
        ControladorDeWifi();
        void establecerConexionWiFi(const char *ssid, const char *passphrase);      
        boolean estaConectado();
        const char* obtenerEstadoDeLaConexion(wl_status_t status);
        //void cambiarCredencialesConexion(const char *ssid, const char *passphrase);
};
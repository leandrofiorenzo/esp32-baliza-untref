#include <WiFi.h>

class ControladorWifi {
    public:
        ControladorWifi();
        void establecerConexionWiFi(char *ssid, char *passphrase);
        boolean estaConectado();
};
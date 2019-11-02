#include <WiFi.h>
#include <WiFiMulti.h>

class ControladorWifi {
    private:
        WiFiMulti wifiMulti;
    public:
        ControladorWifi();
        void establecerConexion(char *ssid, char *passowrd);
        boolean estaConectado();
};
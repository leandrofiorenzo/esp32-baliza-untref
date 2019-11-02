#include <WiFi.h>
#include <WiFiMulti.h>

class ControladorWifi {
    private:
        static WiFiMulti wifiMulti;
    public:
        ControladorWifi(char *ssid, char *passowrd);
        boolean estaConectado();
};
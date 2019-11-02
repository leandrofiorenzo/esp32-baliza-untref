#include "ControladorWifi.hpp"

ControladorWifi::ControladorWifi() {

};

void ControladorWifi::establecerConexion(char *ssid, char *passowrd) {
    wifiMulti.addAP(ssid, passowrd);
};

boolean ControladorWifi::estaConectado() {
    return wifiMulti.run() ==  WL_CONNECTED;
};
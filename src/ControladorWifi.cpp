#include "ControladorWifi.hpp"

ControladorWifi::ControladorWifi(char *ssid, char *passowrd) {
    wifiMulti.addAP(ssid, passowrd);
    wifiMulti.addAP("Fibertel WiFi NUMERO 2", "00416040571");
}
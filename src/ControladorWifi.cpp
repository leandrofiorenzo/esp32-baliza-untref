#include "ControladorWifi.hpp"

ControladorWifi::ControladorWifi() {

};

void ControladorWifi::establecerConexionWiFi(char *ssid, char *passphrase) {
    WiFi.begin(ssid, passphrase);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Conectando a WiFi...");
    }
};

boolean ControladorWifi::estaConectado() {
    return WiFi.status() ==  WL_CONNECTED;
};

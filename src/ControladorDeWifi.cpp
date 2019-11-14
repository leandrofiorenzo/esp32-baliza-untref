#include "ControladorDeWifi.hpp"

ControladorDeWifi::ControladorDeWifi() {

};

void ControladorDeWifi::establecerConexionWiFi(const char *ssid, const char *passphrase) {
    WiFi.disconnect();
    WiFi.begin(ssid, passphrase);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("Se intento conectar y devolvió el estado: ");
        Serial.print(obtenerEstadoDeLaConexion(WiFi.status()));
        Serial.println(". Reintentando en 1 segundo...");
        delay(1000);
    }
};

const char* ControladorDeWifi::obtenerEstadoDeLaConexion(wl_status_t status) {
  switch (status) {
    case WL_NO_SHIELD: return "WL_NO_SHIELD";
    case WL_IDLE_STATUS: return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL: return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED: return "WL_SCAN_COMPLETED";
    case WL_CONNECTED: return "WL_CONNECTED";
    case WL_CONNECT_FAILED: return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST: return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED: return "WL_DISCONNECTED";
    default: return "NO SE";
  }
  return "NO SE";  
}

boolean ControladorDeWifi::estaConectado() {
    return WiFi.status() ==  WL_CONNECTED;
};

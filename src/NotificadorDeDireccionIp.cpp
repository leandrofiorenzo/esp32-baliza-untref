#include "NotificadorDeDireccionIp.h"

void NotificadorDeDireccionIp::notificarDireccionIp() {
    HTTPClient clienteHttp;
    String ip = WiFi.localIP().toString();
    String url = "https://esp32-api.herokuapp.com/api/v1/ip/" + ip;
    clienteHttp.begin(url);
    clienteHttp.POST("");
    clienteHttp.end();
}
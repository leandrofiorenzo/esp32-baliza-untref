#include <WiFi.h>
#include <HTTPClient.h>

#ifndef ControladorDeWifi_H
#define ControladorDeWifi_H

class ControladorDeWifi {
    private:
        const char *nombreRed;
        const char *contrasenaRed;
    public:
        ControladorDeWifi();
        void establecerConexionWiFi();      
        void cambiarCredencialesConexion(const char *_nombreRed, const char *_contrasenaRed);
        boolean estaConectado();
        const char* obtenerEstadoDeLaConexion(wl_status_t status);
        void notificarIPDispositivo();
};

#endif
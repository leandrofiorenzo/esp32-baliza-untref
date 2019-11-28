#include <WiFi.h>
#include <HTTPClient.h>
#include "NotificadorDeDireccionIp.h"

#ifndef ControladorDeWifi_H
#define ControladorDeWifi_H

class ControladorDeWifi {
    private:
        NotificadorDeDireccionIp notificadorDeDireccionIp;
        const char *nombreRed;
        const char *contrasenaRed;
        void imprimirEstadoDeLaConexion();
        
    public:
        ControladorDeWifi();
        boolean estaConectado();
        void establecerConexionWiFi();      
        void cambiarCredencialesConexion(const char *_nombreRed, const char *_contrasenaRed);
};

#endif
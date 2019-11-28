#include "ControladorDeWifi.h"

ControladorDeWifi::ControladorDeWifi() {
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
};

void ControladorDeWifi::establecerConexionWiFi() {
    WiFi.disconnect();
    WiFi.begin(nombreRed, contrasenaRed);

    int cantidadIntentosActuales = 0;
    int cantidadMaximaIntentosReconexion = 10;
    while (WiFi.status() != WL_CONNECTED && cantidadIntentosActuales < cantidadMaximaIntentosReconexion) {
        cantidadIntentosActuales++;
        Serial.print("El intento de conexion ");
        Serial.print(cantidadIntentosActuales);
        Serial.print(" fallo con estado ");
        imprimirEstadoDeLaConexion();
        Serial.println(". Reintentando en 1 segundo...");
        delay(1000);
    }

    if(WiFi.status() != WL_CONNECTED) {
        Serial.println("Se supero la cantidad máxima de intentos. Reconectando con credenciales conocidas.");
        cambiarCredencialesConexion("Redmi", "lfiorenzo123");
    } else {
        Serial.print("Conexión WiFi establecida exitosamente, con IP: "); 
        Serial.println(WiFi.localIP());
        notificadorDeDireccionIp.notificarDireccionIp();
    }
};

boolean ControladorDeWifi::estaConectado() {
    return WiFi.status() ==  WL_CONNECTED;
};

void ControladorDeWifi::cambiarCredencialesConexion(const char *_nombreRed, const char *_contrasenaRed) {
    nombreRed = _nombreRed;
    contrasenaRed = _contrasenaRed;
    establecerConexionWiFi();
}

//Inicio métodos privados
void ControladorDeWifi::imprimirEstadoDeLaConexion() {
    wl_status_t status = WiFi.status();
    switch (status) {
        case WL_NO_SHIELD: {
            Serial.print("WL_NO_SHIELD");
            break;
        }
        case WL_IDLE_STATUS: {
            Serial.print("WL_IDLE_STATUS");
            break;
        }
        case WL_NO_SSID_AVAIL: {
            Serial.print("WL_NO_SSID_AVAIL");
            break;
        }
        case WL_SCAN_COMPLETED: {
            Serial.print("WL_SCAN_COMPLETED");
            break;
        }
        case WL_CONNECTED: {
            Serial.print("WL_CONNECTED");
            break;
        }
        case WL_CONNECT_FAILED: {
            Serial.print("WL_CONNECT_FAILED");
            break;
        }
        case WL_CONNECTION_LOST: {
            Serial.print("WL_CONNECTION_LOST");
            break;
        }
        case WL_DISCONNECTED: {
            Serial.print("WL_DISCONNECTED");
            break;
        }
        default: {
            Serial.print("Estado WiFi desconocido");
            break;
        }
    }  
}
//Fin métodos privados
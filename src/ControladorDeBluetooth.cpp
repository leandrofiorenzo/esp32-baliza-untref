#include "ControladorDeBluetooth.hpp"
#include <ArduinoJson.h>

void callbackBluetooth(esp_spp_cb_event_t event, esp_spp_cb_param_t *param){
    if(event == ESP_SPP_SRV_OPEN_EVT){
        Serial.println("Cliente conectado");
    }
 
    if(event == ESP_SPP_CLOSE_EVT ){
        Serial.println("Cliente desconectado");
    }
}

ControladorDeBluetooth::ControladorDeBluetooth() {
    bluetoothSerial.register_callback(callbackBluetooth);

    if(!bluetoothSerial.begin("ESP32test")) {
        Serial.println("Ocurrió un error al inicializar bluetooth");
    } else {
        Serial.println("Bluetooth inicializado");
    } 
}

String ControladorDeBluetooth::obtenerTipoDeNovedad() {
    String jsonString = bluetoothSerial.readString();
        
    DynamicJsonDocument dynamicJsonDocument(1024);
    deserializeJson(dynamicJsonDocument, jsonString);   
    JsonObject jsonObject = dynamicJsonDocument.as<JsonObject>();
    String type = jsonObject["type"];

    if(type == "WIFI") {
        const char *ssid = jsonObject["ssid"];
        _nombreRed = ssid;

        const char *passphrase = jsonObject["passphrase"];
        _contrasenaRed  = passphrase;

        return type;               
    }

    return "";
};

const char* ControladorDeBluetooth::obtenerNombreRed () {
    return _nombreRed;
};

const char* ControladorDeBluetooth::obtenerContrasenaRed () {
    return _contrasenaRed;
};
#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/CircleCIStrategy.hpp"

ManejadorDelPrograma manejadorDelPrograma;

#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

void setup () {
    Serial.begin(115200);
    SerialBT.begin("ESP32test"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    //const char* ssid = "Fibertel WiFi NUMERO 2";
    //const char* passphrase = "00416040571";
    //const char* ssid = "WiFiSTI";
    //const char* passphrase = "solu*1234";
    //const char* ssid = "wifi18878";
    //const char* passphrase = "51883488";
    //manejadorDelPrograma.establecerConexionWiFi(ssid, passphrase);
}

void loop () {
    if (Serial.available()) {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available()) {
        Serial.write(SerialBT.read());
    }
    delay(20);

    //TravisCI
    // TravisStrategy *travisStrategy = new TravisStrategy();
    // const char* tokenAccesso = "zxiel_jS6Xaaok3zgnHGzQ";
    // travisStrategy->definirTokenAcceso(tokenAccesso); 
    // const char* repositorioId = "27012148";
    // travisStrategy->definirRepositorioId(repositorioId);  
    // manejadorDelPrograma.definirServidorDeIntegracionContinua(travisStrategy);

    //CircleCI
    //CircleCIStrategy *circleCIStrategy = new CircleCIStrategy();
    //manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);
    
    //ESTO VA SIEMPRE
    //manejadorDelPrograma.ejecutarRutinaDeVerificacion();
}
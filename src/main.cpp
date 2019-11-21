#include <Arduino.h>

#include "ManejadorDelPrograma.hpp"

#include "estrategias-integracion-continua/TravisStrategy.hpp"
#include "estrategias-integracion-continua/CircleCIStrategy.hpp"

ManejadorDelPrograma manejadorDelPrograma;

void setup () {
    Serial.begin(115200);
    const char* ssid = "Fibertel WiFi NUMERO 2";
    const char* passphrase = "00416040571";
    //const char* ssid = "WiFiSTI";
    //const char* passphrase = "solu*1234";
    //const char* ssid = "wifi18878";
    //const char* passphrase = "51883488";
    manejadorDelPrograma.establecerConexionWiFi(ssid, passphrase);
}

void loop () {
    //TravisCI  
    TravisStrategy *travisStrategy = new TravisStrategy();

    const char* tokenAccesso = "zxiel_jS6Xaaok3zgnHGzQ";
    travisStrategy->definirTokenAcceso(tokenAccesso);
    
    const char* repositorioId = "26796622";
    travisStrategy->definirRepositorioId(repositorioId);

    manejadorDelPrograma.definirServidorDeIntegracionContinua(travisStrategy);

    //CircleCI
    //CircleCIStrategy *circleCIStrategy = new CircleCIStrategy();
    //manejadorDelPrograma.definirServidorDeIntegracionContinua(circleCIStrategy);

    //No comentar esta linea
    manejadorDelPrograma.ejecutarRutinaDeVerificacion();
}
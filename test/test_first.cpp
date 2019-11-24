#include <Arduino.h>
#include <unity.h>

#define LED_BUILTIN 13

#include "ManejadorDelPrograma.h"
#include "mocks/MockBuildExitoso.cpp"
#include "mocks/MockBuildFallido.cpp"
#include "mocks/MockControladorDeWifi.cpp"

void testUltimoBuildExitosoConPushExitosoNoCambiaEstado(void) { 
    MockBuildExitoso mockBuildExitoso;

    //Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, mockBuildExitoso.obtenerEstadoUltimoBuild());
    
    //Cuando haya un push al repositorio y el estado del build sea exitoso 
    EstadoBuildEnum ultimoBuild = mockBuildExitoso.obtenerEstadoUltimoBuild();
    
    //Entonces el ESP32 debe permanecer en estado exitoso (led verde)
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, ultimoBuild);
}

//Dado un ESP32 encendido        
//Cuando se le asigna un servidor de Integracion Continua      
//Entonces el ESP32 se debe conectar con el servidor por WIFI  
void testConexionDeLaBalizaAlServidorDeIntegracionContinuaATravesDeWiFi(void) {
    MockControladorDeWifi *mockControladorDeWifi = new MockControladorDeWifi();
    ManejadorDelPrograma manejadorDelPrograma(mockControladorDeWifi);

    TEST_ASSERT_TRUE(mockControladorDeWifi->estaConectado());

    //MockBuildExitoso *mockBuildExitoso1 = new MockBuildExitoso();

    //manejadorDelPrograma.definirServidorDeIntegracionContinua(mockBuildExitoso1);
}

void test_led_state_high(void) {
    digitalWrite(LED_BUILTIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_led_state_low(void) {
    digitalWrite(LED_BUILTIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void setup() {
    delay(2000);

    UNITY_BEGIN();   
    RUN_TEST(testUltimoBuildExitosoConPushExitosoNoCambiaEstado);
    RUN_TEST(testConexionDeLaBalizaAlServidorDeIntegracionContinuaATravesDeWiFi);
    

    pinMode(LED_BUILTIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 1;

void loop() {
    if (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); // stop unit testing
    }
}
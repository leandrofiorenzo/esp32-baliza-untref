#include <Arduino.h>
#include <unity.h>

#define LED_BUILTIN 13

#include "ManejadorDelPrograma.h"
#include "mocks/MockBuildExitoso.cpp"
#include "mocks/MockBuildFallido.cpp"
#include "mocks/MockControladorDeWifiConectado.cpp"
#include "mocks/MockControladorDeLeds.cpp"

/***** 1° Criterio de Aceptacion *****/

void testUltimoBuildExitosoConPushExitosoNoCambiaEstado(void) { 
    MockBuildExitoso mockBuildExitoso("", "");

    //Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, mockBuildExitoso.obtenerEstadoUltimoBuild());
    
    //Cuando haya un push al repositorio y el estado del build sea exitoso 
    EstadoBuildEnum ultimoBuild = mockBuildExitoso.obtenerEstadoUltimoBuild();
    
    //Entonces el ESP32 debe permanecer en estado exitoso (led verde)
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, ultimoBuild);
}
  
void testUltimoBuildFallidoConPushFallidoNoCambiaEstado(void) { 
    MockBuildFallido MockBuildFallido("", "");

    //Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido 
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Fallido, MockBuildFallido.obtenerEstadoUltimoBuild());
    
    //Cuando haya un push al repositorio y el estado del build sea fallido  
    EstadoBuildEnum ultimoBuild = MockBuildFallido.obtenerEstadoUltimoBuild();
    
    //Entonces el ESP32 debe permanecer en estado fallido (led rojo)
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Fallido, ultimoBuild);
}

void testUltimoBuildExitosoConPushFallidoCambiaEstado(void) { 
    MockBuildFallido MockBuildFallido("", "");
    MockBuildExitoso MockBuildExitoso("", "");

    //Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso 
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, MockBuildExitoso.obtenerEstadoUltimoBuild());
    
    //Cuando haya un push al repositorio y el estado del build sea fallido  
    EstadoBuildEnum ultimoBuild = MockBuildFallido.obtenerEstadoUltimoBuild();
    
    //Entonces el ESP32 debe cambiar el estado a fallido (led rojo)
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Fallido, ultimoBuild);
}

void testUltimoBuildFallidoConPushExitosoCambiaEstado(void) { 
    MockBuildFallido MockBuildFallido("", "");
    MockBuildExitoso MockBuildExitoso("", "");

    //Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Fallido, MockBuildFallido.obtenerEstadoUltimoBuild());
    
    //Cuando haya un push al repositorio y el estado del build sea exitoso   
    EstadoBuildEnum ultimoBuild = MockBuildExitoso.obtenerEstadoUltimoBuild();
    
    //Entonces el ESP32 debe cambiar el estado a exitoso
    TEST_ASSERT_EQUAL(EstadoBuildEnum::Exitoso, ultimoBuild);
}

/***** 2° Criterio de Aceptacion *****/

// Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
// Cuando el estado del build sea exitoso  
// Entonces el ESP32 debe encender el led verde de la baliza  

// Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
// Cuando el estado del build sea fallido  
// Entonces el ESP32 debe encender el led rojo de la baliza

/***** 4° Criterio de Aceptacion *****/

void testConexionDeLaBalizaAlServidorDeIntegracionContinuaATravesDeWiFi(void) {
    //Dado un ESP32 encendido
    MockControladorDeWifiConectado *mockControladorDeWifi = new MockControladorDeWifiConectado();
    MockControladorDeLeds *mockControladorDeLeds = new MockControladorDeLeds();
    ManejadorDelPrograma manejadorDelPrograma(mockControladorDeWifi, mockControladorDeLeds);

    MockBuildExitoso *mockBuildExitoso = new MockBuildExitoso("", "");
    
    //Cuando se le asigna un servidor de Integracion Continua 
    manejadorDelPrograma.definirServidorDeIntegracionContinua(mockBuildExitoso);

    //Entonces el ESP32 se debe conectar con el servidor por WIFI  
    TEST_ASSERT_TRUE(mockControladorDeWifi->estaConectado());
}

// void test_led_state_high(void) {
//     digitalWrite(LED_BUILTIN, HIGH);
//     TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
// }

// void test_led_state_low(void) {
//     digitalWrite(LED_BUILTIN, LOW);
//     TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
// }

void setup() {
    delay(2000);

    UNITY_BEGIN();   

    RUN_TEST(testUltimoBuildExitosoConPushExitosoNoCambiaEstado);
    RUN_TEST(testConexionDeLaBalizaAlServidorDeIntegracionContinuaATravesDeWiFi);
    
    //pinMode(LED_BUILTIN, OUTPUT);
    UNITY_END();
}

// uint8_t i = 0;
// uint8_t max_blinks = 1;

void loop() {
    // if (i < max_blinks)
    // {
    //     RUN_TEST(test_led_state_high);
    //     delay(500);
    //     RUN_TEST(test_led_state_low);
    //     delay(500);
    //     i++;
    // }
    // else if (i == max_blinks) {
    //   UNITY_END(); // stop unit testing
    // }
}
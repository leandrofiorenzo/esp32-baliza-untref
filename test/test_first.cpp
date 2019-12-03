#include <Arduino.h>
#include <unity.h>

#define LED_BUILTIN 13

#include "ManejadorDelPrograma.h"
#include "mocks/MockBuildExitoso.cpp"
#include "mocks/MockBuildFallido.cpp"
#include "mocks/MockBuildEnCurso.cpp"
#include "mocks/MockControladorDeWifiConectado.cpp"
#include "mocks/MockControladorDeWifiDesconectado.cpp"
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

void testConectadoAWifiConPushExitosoEnciendeLedVerde(void) {
    MockBuildExitoso MockBuildExitoso("", "");
    MockControladorDeWifiConectado *mockControladorDeWifi = new MockControladorDeWifiConectado();
    MockControladorDeLeds *mockControladorDeLeds = new MockControladorDeLeds();

    // Dado un ESP32 conectado por WiFi a un servidor de Integración Continua
    TEST_ASSERT_TRUE(mockControladorDeWifi->estaConectado());

    // Cuando el estado del build sea exitoso 
    EstadoBuildEnum ultimoBuild = MockBuildExitoso.obtenerEstadoUltimoBuild(); 

    mockControladorDeLeds->prenderLedCorrespondienteAlEstadoBuild(ultimoBuild);

    // Entonces el ESP32 debe encender el led verde de la baliza
    TEST_ASSERT_EQUAL(HIGH, digitalRead(22));
}

void testConectadoAWifiConPushFallidoEnciendeLedRojo(void) {
    MockBuildFallido MockBuildFallido("", "");
    MockControladorDeWifiConectado *mockControladorDeWifi = new MockControladorDeWifiConectado();
    MockControladorDeLeds *mockControladorDeLeds = new MockControladorDeLeds();

    // Dado un ESP32 conectado por WiFi a un servidor de Integración Continua 
    TEST_ASSERT_TRUE(mockControladorDeWifi->estaConectado());

    // Cuando el estado del build sea fallido  
    EstadoBuildEnum ultimoBuild = MockBuildFallido.obtenerEstadoUltimoBuild(); 

    mockControladorDeLeds->prenderLedCorrespondienteAlEstadoBuild(ultimoBuild);

    // Entonces el ESP32 debe encender el led rojo de la baliza
    TEST_ASSERT_EQUAL(HIGH, digitalRead(23));
}

/***** 3° Criterio de Aceptacion *****/

void testConectadoAWifiConPushEnCursoDeValidacionEnciendeLedAzul(void) {
    MockBuildEnCurso MockBuildEnCurso("", "");
    MockControladorDeWifiConectado *mockControladorDeWifi = new MockControladorDeWifiConectado();
    MockControladorDeLeds *mockControladorDeLeds = new MockControladorDeLeds();

    // Dado un ESP32 conectado por WiFi a un servidor de Integración Continua  
    TEST_ASSERT_TRUE(mockControladorDeWifi->estaConectado());

    // Cuando haya un push al repositorio y el build se encuentre en curso
    EstadoBuildEnum ultimoBuild = MockBuildEnCurso.obtenerEstadoUltimoBuild(); 

    mockControladorDeLeds->prenderLedCorrespondienteAlEstadoBuild(ultimoBuild);

    // Entonces el ESP32 debe encender el led azul de la baliza mientras se procesa
    TEST_ASSERT_EQUAL(HIGH, digitalRead(21));
}


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

    EstadoBuildEnum ultimoEstadoConexion = EstadoBuildEnum::ConectadoWIFI;

    mockControladorDeLeds->prenderLedCorrespondienteAlEstadoConexion(ultimoEstadoConexion);

    TEST_ASSERT_EQUAL(HIGH, digitalRead(19));
    TEST_ASSERT_EQUAL(LOW, digitalRead(18));
}

/***** 5° Criterio de Aceptacion *****/

void testConectadoAWiFiSeDesconecta(void) {
    //Dado un ESP32 encendido
    MockControladorDeWifiConectado *mockControladorDeWifiConectado = new MockControladorDeWifiConectado();
    MockControladorDeWifiDesconectado *mockControladorDeWifiDesconectado = new MockControladorDeWifiDesconectado();
    MockControladorDeLeds *mockControladorDeLeds = new MockControladorDeLeds();

    // Dado un ESP32 conectado por WiFi 
    TEST_ASSERT_TRUE(mockControladorDeWifiConectado->estaConectado());

    // Cuando se pierda la conexion por WiFi    
    TEST_ASSERT_FALSE(mockControladorDeWifiDesconectado->estaConectado());

    EstadoBuildEnum ultimoEstadoConexion = EstadoBuildEnum::DesconexionWIFI;

    mockControladorDeLeds->prenderLedCorrespondienteAlEstadoConexion(ultimoEstadoConexion);

    // Entonces el ESP32 debe apagar la luz amarilla y  encender la luz roja del costado de la baliza
    TEST_ASSERT_EQUAL(HIGH, digitalRead(18));
    TEST_ASSERT_EQUAL(LOW, digitalRead(19));

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
    RUN_TEST(testUltimoBuildFallidoConPushFallidoNoCambiaEstado);
    RUN_TEST(testUltimoBuildExitosoConPushFallidoCambiaEstado);
    RUN_TEST(testUltimoBuildFallidoConPushExitosoCambiaEstado);
    RUN_TEST(testConectadoAWifiConPushExitosoEnciendeLedVerde);
    RUN_TEST(testConectadoAWifiConPushFallidoEnciendeLedRojo);
    RUN_TEST(testConectadoAWifiConPushEnCursoDeValidacionEnciendeLedAzul);
    RUN_TEST(testConexionDeLaBalizaAlServidorDeIntegracionContinuaATravesDeWiFi);
    RUN_TEST(testConectadoAWiFiSeDesconecta);
    
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
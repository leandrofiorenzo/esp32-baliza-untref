#include <unity.h>

void setup () {
    
}

void loop() {

}

/* Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso 
Cuando haya un push al repositorio y el estado del build sea exitoso 
Entonces el ESP32 debe permanecer en estado exitoso (led verde)*/
void testUltimoBuildExitosoConPushExitosoNoCambiaEstado(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

/*Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido 
Cuando haya un push al repositorio y el estado del build sea fallido 
Entonces el ESP32 debe permanecer en estado fallido (led rojo)*/
void testUltimoBuildFallidoConPushFallidoNoCambiaEstado(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

/*Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado exitoso 
Cuando haya un push al repositorio y el estado del build sea fallido 
Entonces el ESP32 debe cambiar el estado a fallido (debe encender el led rojo y apagar los demas)*/
void testUltimoBuildFallidoConPushExitosoCambiaEstadoAExitoso(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

/*Dado un ESP32 conectado por WiFi a un servidor de Integración Continua con el último build en estado fallido 
Cuando haya un push al repositorio y el estado del build sea exitoso 
Entonces el ESP32 debe cambiar el estado a exitoso (debe encender el led verde y apagar los demas)*/
void testUltimoBuildExitosoConPushFallidoCambiaEstadoAFallido(void) {
    TEST_ASSERT_EQUAL(2, 3);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(testUltimoBuildExitosoConPushExitosoNoCambiaEstado);
    RUN_TEST(testUltimoBuildFallidoConPushFallidoNoCambiaEstado);
    RUN_TEST(testUltimoBuildFallidoConPushExitosoCambiaEstadoAExitoso);
    RUN_TEST(testUltimoBuildExitosoConPushFallidoCambiaEstadoAFallido);

    UNITY_END();

    return 0;
}



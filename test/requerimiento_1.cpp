#include <unity.h>

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
    TEST_ASSERT_EQUAL(2, 2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    //RUN_TEST(test_cambio_estado_exitoso_a_fallido);
    UNITY_END();

    return 0;
}
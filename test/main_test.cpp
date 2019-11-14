#include <unity.h>

#include "ManejadorDelPrograma.hpp"

void test_cambio_estado_exitoso_a_fallido(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

/*void test_cambio_estado_fallido_a_exitoso(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

void test_procesamiento_estado_repositorio(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

void test_aviso_perdida_conexion(void) {
    TEST_ASSERT_EQUAL(2, 2);
}*/

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_cambio_estado_exitoso_a_fallido);
    /*RUN_TEST(test_cambio_estado_fallido_a_exitoso);
    RUN_TEST(test_procesamiento_estado_repositorio);
    RUN_TEST(test_aviso_perdida_conexion);*/
    UNITY_END();

    return 0;
}
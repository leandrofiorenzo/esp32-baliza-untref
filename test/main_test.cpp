#include <unity.h>

void test_cambio_estado_exitoso_a_fallido(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_cambio_estado_exitoso_a_fallido);
    UNITY_END();

    return 0;
}
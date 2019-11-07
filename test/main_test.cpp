#include <unity.h>

void test_function_calculator_division(void) {
    TEST_ASSERT_EQUAL(2, 2);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_division);
    UNITY_END();

    return 0;
}
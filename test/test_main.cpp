#include <unity.h>

void test_function_calculator_addition(void) {
    TEST_ASSERT_EQUAL(32, 30);
}

void test_function_calculator_subtraction(void) {
    TEST_ASSERT_EQUAL(20, 21);
}

void test_function_calculator_multiplication(void) {
    TEST_ASSERT_EQUAL(50, 55);
}

void test_function_calculator_division(void) {
    TEST_ASSERT_EQUAL(32, 30);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_function_calculator_addition);
    RUN_TEST(test_function_calculator_subtraction);
    RUN_TEST(test_function_calculator_multiplication);
    RUN_TEST(test_function_calculator_division);
    UNITY_END();

    return 0;
}
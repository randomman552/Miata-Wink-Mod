#include <Arduino.h>
#include <IO.h>
#include <InputManager.h>
#include <unity.h>

// Create objects
SimulatedDigitalIO inputIO;
InputManager inputManager(&inputIO, 300);

void reset_between_tests()
{
    inputIO.off();
    inputManager.clear();
    inputManager.setup();
    delay(100);
}

void test_starts_null()
{
    auto sequence = inputManager.check(0);
    TEST_ASSERT_NULL(sequence);
    inputManager.clear();
}

void test_clear()
{
    auto sequence = inputManager.check(0);
    inputIO.on();
    inputManager.check(0);

    sequence = inputManager.check(500);
    TEST_ASSERT_NOT_NULL(sequence);
    TEST_ASSERT_EQUAL(1, sequence->size());
    inputManager.clear();
    TEST_ASSERT_EQUAL(0, sequence->size());
}

void test_single_input()
{
    auto sequence = inputManager.check(0);
    inputIO.on();
    inputManager.check(0);

    sequence = inputManager.check(500);
    TEST_ASSERT_NOT_NULL(sequence);
    TEST_ASSERT_EQUAL(1, sequence->size());
}

void test_simple_sequence()
{
    auto sequence = inputManager.check(0);

    // Result should be on, off, on
    inputIO.on();
    inputManager.check(0);
    inputIO.off();
    inputManager.check(0);
    inputIO.on();
    inputManager.check(0);

    // Check result after input delay has passed
    sequence = inputManager.check(500);
    TEST_ASSERT_NOT_NULL(sequence);
    TEST_ASSERT_EQUAL(3, sequence->size());
    TEST_ASSERT_EQUAL(true, sequence->get(0));
    TEST_ASSERT_EQUAL(false, sequence->get(1));
    TEST_ASSERT_EQUAL(true, sequence->get(2));
}

void setup()
{
    inputIO.setup();
    inputIO.off();

    inputManager.setup();

    UNITY_BEGIN();
    delay(1000);

    RUN_TEST(test_starts_null);
    reset_between_tests();

    RUN_TEST(test_clear);
    reset_between_tests();

    RUN_TEST(test_single_input);
    reset_between_tests();

    RUN_TEST(test_simple_sequence);
    reset_between_tests();

    UNITY_END();
}

void loop()
{
    delay(1000);
}
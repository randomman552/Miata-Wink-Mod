#include <Arduino.h>
#include <IO.h>
#include <unity.h>

DigitalIO led(LED_BUILTIN);

void test_write_high()
{
    led.on();

    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_BUILTIN));
}

void test_write_low()
{
    led.off();

    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_BUILTIN));
}

void test_read_high()
{
    digitalWrite(LED_BUILTIN, HIGH);

    TEST_ASSERT_EQUAL(true, led.isOn());
    TEST_ASSERT_EQUAL(false, led.isOff());
}

void test_read_low()
{
    digitalWrite(LED_BUILTIN, LOW);

    TEST_ASSERT_EQUAL(false, led.isOn());
    TEST_ASSERT_EQUAL(true, led.isOff());
}

void setup()
{
    led.setup();

    UNITY_BEGIN();
}

void loop()
{
    RUN_TEST(test_write_high);
    RUN_TEST(test_write_low);

    RUN_TEST(test_read_high);
    RUN_TEST(test_read_low);

    UNITY_END();
}
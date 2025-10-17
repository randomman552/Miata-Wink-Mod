#include <Arduino.h>
#include <Popup.h>
#include <unity.h>

#define LEFT_UP_PIN 11
#define LEFT_DOWN_PIN 10
#define RIGHT_UP_PIN 9
#define RIGHT_DOWN_PIN 8

Popup leftPopup(LEFT_UP_PIN, LEFT_DOWN_PIN);
Popup rightPopup(RIGHT_UP_PIN, RIGHT_DOWN_PIN);

void test_up(Popup *lamp)
{
    lamp->up();
    delay(2000);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(lamp->_upPin));
    TEST_ASSERT_EQUAL(LOW, digitalRead(lamp->_downPin));
}

void test_down(Popup *lamp)
{
    lamp->down();
    delay(2000);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(lamp->_downPin));
    TEST_ASSERT_EQUAL(LOW, digitalRead(lamp->_upPin));
}

void test_sleep(Popup *lamp)
{
    lamp->sleep();
    delay(2000);
    TEST_ASSERT_EQUAL(LOW, digitalRead(lamp->_downPin));
    TEST_ASSERT_EQUAL(LOW, digitalRead(lamp->_upPin));
}

void test_left_up()
{
    test_up(&leftPopup);
}

void test_left_down()
{
    test_down(&leftPopup);
}

void test_left_sleep()
{
    test_sleep(&leftPopup);
}

void test_right_up()
{
    test_up(&rightPopup);
}

void test_right_down()
{
    test_down(&rightPopup);
}

void test_right_sleep()
{
    test_sleep(&rightPopup);
}

void setup()
{
    leftPopup.setup();
    rightPopup.setup();

    UNITY_BEGIN();
}

void loop()
{
    RUN_TEST(test_left_up);
    RUN_TEST(test_left_down);
    RUN_TEST(test_left_sleep);

    RUN_TEST(test_right_up);
    RUN_TEST(test_right_down);
    RUN_TEST(test_right_sleep);

    UNITY_END();
}
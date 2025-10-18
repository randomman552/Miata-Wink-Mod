#include <Arduino.h>
#include <Animation.h>
#include <unity.h>

#define LEFT_UP_PIN 11
#define LEFT_DOWN_PIN 10
#define RIGHT_UP_PIN 9
#define RIGHT_DOWN_PIN 8

// Create IO
DigitalIO leftUpIO(LEFT_UP_PIN);
DigitalIO leftDownIO(LEFT_DOWN_PIN);
DigitalIO rightUpIO(RIGHT_UP_PIN);
DigitalIO rightDownIO(RIGHT_DOWN_PIN);

// Create popup's
Popup leftPopup(&leftUpIO, &leftDownIO);
Popup rightPopup(&rightUpIO, &rightDownIO);

void test_up_animation()
{
    UpAnimation anim(&leftPopup, &rightPopup);

    anim.animate();

    TEST_ASSERT(leftUpIO.isOn());
    TEST_ASSERT(leftDownIO.isOff());
    TEST_ASSERT(rightUpIO.isOn());
    TEST_ASSERT(rightDownIO.isOff());
}

void test_down_animation()
{
    DownAnimation anim(&leftPopup, &rightPopup);

    anim.animate();

    TEST_ASSERT(leftUpIO.isOff());
    TEST_ASSERT(leftDownIO.isOn());
    TEST_ASSERT(rightUpIO.isOff());
    TEST_ASSERT(rightDownIO.isOn());
}

void setup()
{
    leftUpIO.setup();
    leftDownIO.setup();
    rightUpIO.setup();
    rightDownIO.setup();

    UNITY_BEGIN();
}

void loop()
{
    RUN_TEST(test_up_animation);
    RUN_TEST(test_down_animation);

    UNITY_END();
}
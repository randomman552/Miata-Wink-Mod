#include <Arduino.h>
#include <ActivityMonitor.h>
#include <unity.h>

#define INACTIVITY_TIMEOUT 300000

ActivityMonitor monitor(INACTIVITY_TIMEOUT);

void test_starts_true()
{
    TEST_ASSERT(monitor.isActive(0));
}

void test_expires()
{
    TEST_ASSERT_FALSE(monitor.isActive(INACTIVITY_TIMEOUT));
}

void test_reset()
{
    monitor.setLastActive(INACTIVITY_TIMEOUT);
    TEST_ASSERT_FALSE(monitor.isActive(INACTIVITY_TIMEOUT * 2));
}

void setup()
{
    UNITY_BEGIN();
}

void loop()
{
    RUN_TEST(test_starts_true);
    RUN_TEST(test_expires);
    RUN_TEST(test_reset);

    UNITY_END();
}
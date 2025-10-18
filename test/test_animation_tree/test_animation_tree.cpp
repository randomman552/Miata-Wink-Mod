#include <Arduino.h>
#include <Animation.h>
#include <AnimationTree.h>
#include <LinkedList.h>
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

// Animations
UpAnimation upAnim(&leftPopup, &rightPopup);
DownAnimation downAnim(&leftPopup, &rightPopup);

// Build animation tree
AnimationTreeNode upNode(&upAnim);
AnimationTreeNode downNode(&downAnim);
AnimationTreeNode root(&upNode, &downNode);

void test_simple_tree()
{
    // Test navigation to on side
    LinkedList<bool> path;
    path.add(true);
    auto anim = root.find(&path);
    TEST_ASSERT_NOT_NULL(anim);
    TEST_ASSERT_EQUAL(anim, &upAnim);
    anim->animate();

    // Test in other direction
    path.clear();
    path.add(false);
    anim = root.find(&path);
    TEST_ASSERT_NOT_NULL(anim);
    TEST_ASSERT_EQUAL(anim, &downAnim);
    anim->animate();
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
    RUN_TEST(test_simple_tree);

    UNITY_END();
}
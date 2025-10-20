#include <Arduino.h>
#include <Popup.h>
#include <InputManager.h>
#include <Animation.h>
#include <AnimationTree.h>

#define INPUT_PIN 12
#define INPUT_DELAY 300
#define LEFT_UP_PIN 11
#define LEFT_DOWN_PIN 10
#define RIGHT_UP_PIN 9
#define RIGHT_DOWN_PIN 8

// Create IO
DigitalIO inputIO(INPUT_PIN);
DigitalIO leftUpIO(LEFT_UP_PIN);
DigitalIO leftDownIO(LEFT_DOWN_PIN);
DigitalIO rightUpIO(RIGHT_UP_PIN);
DigitalIO rightDownIO(RIGHT_DOWN_PIN);

// Create hardware control objects
Popup leftPopup(&leftUpIO, &leftDownIO);
Popup rightPopup(&rightUpIO, &rightDownIO);
InputManager inputManager(&inputIO, INPUT_DELAY);

// Create animations
UpAnimation upAnimation(&leftPopup, &rightPopup);
DownAnimation downAnimation(&leftPopup, &rightPopup);

// Create animation tree
AnimationTreeNode upNode(&upAnimation);
AnimationTreeNode downNode(&downAnimation);
AnimationTreeNode root(&upNode, &downNode);

void setup()
{
  // Setup hardware
  inputIO.setup();
  leftUpIO.setup();
  leftDownIO.setup();
  rightUpIO.setup();
  rightDownIO.setup();
  inputManager.setup();

  // Start serial
  Serial.begin(9600);
}

void loop()
{
  // Poll inputs for input sequence
  auto tick = millis();
  auto sequence = inputManager.check(tick);

  // If set, perform animation and clear sequence
  if (sequence != nullptr)
  {
    auto animation = root.find(sequence);
    animation->animate();
    inputManager.clear();
  }
}

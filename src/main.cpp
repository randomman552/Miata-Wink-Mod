#include <Arduino.h>
#include <Popup.h>

#define LEFT_UP_PIN 11
#define LEFT_DOWN_PIN 10
#define RIGHT_UP_PIN 9
#define RIGHT_DOWN_PIN 8

Popup leftPopup(LEFT_UP_PIN, LEFT_DOWN_PIN);
Popup rightPopup(RIGHT_UP_PIN, RIGHT_DOWN_PIN);

void setup()
{
  leftPopup.setup();
  rightPopup.setup();

  // Start serial
  Serial.begin(9600);
}

void loop()
{
  leftPopup.up();
  Serial.println("LEFT UP");
  delay(1000);
  leftPopup.sleep();

  rightPopup.up();
  Serial.println("RIGHT UP");
  delay(1000);
  rightPopup.sleep();

  leftPopup.down();
  Serial.println("LEFT DOWN");
  delay(1000);
  leftPopup.sleep();

  rightPopup.down();
  Serial.println("RIGHT DOWN");
  delay(1000);
  rightPopup.sleep();
}

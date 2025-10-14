#include <Arduino.h>
#include <PopupHeadlamp.h>

#define LEFT_UP_PIN 11
#define LEFT_DOWN_PIN 10
#define RIGHT_UP_PIN 9
#define RIGHT_DOWN_PIN 8

PopupHeadlamp left(LEFT_UP_PIN, LEFT_DOWN_PIN);
PopupHeadlamp right(RIGHT_UP_PIN, RIGHT_DOWN_PIN);

void setup()
{
  // Configure IO
  pinMode(LEFT_UP_PIN, OUTPUT);
  pinMode(LEFT_DOWN_PIN, OUTPUT);
  pinMode(RIGHT_UP_PIN, OUTPUT);
  pinMode(RIGHT_DOWN_PIN, OUTPUT);

  // Start serial
  Serial.begin(9600);
}

void loop()
{
  left.up();
  Serial.println("LEFT UP");
  delay(1000);
  left.sleep();

  right.up();
  Serial.println("RIGHT UP");
  delay(1000);
  right.sleep();

  left.down();
  Serial.println("LEFT DOWN");
  delay(1000);
  left.sleep();

  right.down();
  Serial.println("RIGHT DOWN");
  delay(1000);
  right.sleep();
}

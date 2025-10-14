#include <Arduino.h>

const uint8_t LEFT_UP_PIN = 11;
const uint8_t LEFT_DOWN_PIN = 10;
const uint8_t RIGHT_UP_PIN = 9;
const uint8_t RIGHT_DOWN_PIN = 8;

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
  digitalWrite(LEFT_UP_PIN, HIGH);
  Serial.println("LEFT UP");
  delay(1000);
  digitalWrite(LEFT_UP_PIN, LOW);

  digitalWrite(RIGHT_UP_PIN, HIGH);
  Serial.println("RIGHT UP");
  delay(1000);
  digitalWrite(RIGHT_UP_PIN, LOW);

  digitalWrite(LEFT_DOWN_PIN, HIGH);
  Serial.println("LEFT DOWN");
  delay(1000);
  digitalWrite(LEFT_DOWN_PIN, LOW);

  digitalWrite(RIGHT_DOWN_PIN, HIGH);
  Serial.println("RIGHT DOWN");
  delay(1000);
  digitalWrite(RIGHT_DOWN_PIN, LOW);
}

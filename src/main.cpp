#include <Arduino.h>

const int BLED = 11;
const int GLED = 10;
const int RLED = 9;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode = 0;

void setup()
{

  pinMode(RLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{

  for (int i = 0, j = 255; i < 255, j >= 0; i++, j--)
  {
    analogWrite(GLED, i);
    analogWrite(BLED, j);
    delay(10);
  }

  for (int i = 0, j = 255; i < 255, j >= 0; i++, j--)
  {
    analogWrite(BLED, i);
    analogWrite(GLED, j);
    delay(10);
  }

  for (int i = 0, j = 255; i < 255, j >= 0; i++, j--)
  {
    analogWrite(RLED, i);
    analogWrite(BLED, j);
    delay(10);
  }

  for (int i = 0, j = 255; i < 255, j >= 0; i++, j--)
  {
    analogWrite(GLED, i);
    analogWrite(RLED, j);
    delay(10);
  }

  for (int i = 0, j = 255; i < 255, j >= 0; i++, j--)
  {
    analogWrite(BLED, i);
    analogWrite(GLED, j);
    delay(10);
  }
}
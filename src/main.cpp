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

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
    return current;
  }
}

void setMode(int mode)
{
  if (mode == 1)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, LOW);
  }
  else if (mode == 2)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, HIGH);
    digitalWrite(GLED, LOW);
  }
  else if (mode == 3)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(BLED, LOW);
    digitalWrite(GLED, HIGH);
  }
  else if (mode == 4)
  {
    analogWrite(RLED, 127);
    analogWrite(BLED, 0);
    analogWrite(GLED, 127);
  }
  else if (mode == 5)
  {
    analogWrite(RLED, 0);
    analogWrite(BLED, 127);
    analogWrite(GLED, 127);
  }
  else if (mode == 6)
  {
    analogWrite(RLED, 127);
    analogWrite(BLED, 127);
    analogWrite(GLED, 0);
  }
  else if (mode == 7)
  {
    analogWrite(RLED, 215);
    analogWrite(BLED, 20);
    analogWrite(GLED, 20);
  }
  else
  {
    analogWrite(RLED, LOW);
    analogWrite(BLED, LOW);
    analogWrite(GLED, LOW);
  }
}

void loop()
{
  currentButton = debounce(lastButton);
  if (lastButton == LOW && currentButton == HIGH)
  {
    ledMode++;
  }
  lastButton = currentButton;

  if (ledMode == 8)
    ledMode = 0;
  setMode(ledMode);
}
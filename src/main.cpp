#include <Arduino.h>

const int LED = 9;
const int BUTTON = 2;

boolean lastButton = LOW;
boolean currentButton = LOW;

bool ledOn = false;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  digitalWrite(LED, HIGH);
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(BUTTON);

  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
}

void loop()
{
  currentButton = debounce(lastButton);

  if (lastButton == LOW && currentButton == HIGH)
  {
    ledOn = !ledOn;
  }

  lastButton = currentButton;

  digitalWrite(LED, ledOn);
}

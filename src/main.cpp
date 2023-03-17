#include <Arduino.h>

const int POD = 0;
int val = 0;

void setup()
{

  Serial.begin(9600);
}

void loop()
{
  val = analogRead(POD);
  Serial.println(val);
  delay(1000);
}
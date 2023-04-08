#include <Arduino.h>

const int TEMP = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int reading = analogRead(TEMP);
  float voltage = reading * 5.0;
  voltage /= 1024;
  Serial.println("voltage: " + String(voltage));
  float temperature = voltage * 100;
  Serial.println("temp: " + String(temperature));
  delay(2000);
}
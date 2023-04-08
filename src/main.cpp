#include <Arduino.h>

int speakerPin = 9;
// Note frequencies
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_B4 494
#define NOTE_C5 523

void setup()
{
  pinMode(speakerPin, OUTPUT);
}

void loop()
{
  // Verse 1
  tone(speakerPin, NOTE_G4, 250);
  delay(250);
  tone(speakerPin, NOTE_G4, 250);
  delay(250);
  tone(speakerPin, NOTE_A4, 500);
  delay(500);
  tone(speakerPin, NOTE_G4, 500);
  delay(500);
  tone(speakerPin, NOTE_C5, 500);
  delay(500);

  // Verse 2
  tone(speakerPin, NOTE_B4, 1000);
  delay(1000);
}

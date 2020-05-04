#include <Arduino.h>

#define LED_STATUS    1
#define EXT_TRIGGER   3
#define PHOTO_TRIGGER 4

#define PHOTO_TRIGGER_PERIOD_MS 30000
//#define PHOTO_TRIGGER_PERIOD_MS 5000
#define PHOTO_TRIGGER_MS        25


void setup() {
  // this is on board LED
  pinMode(LED_STATUS,  OUTPUT);
  // external button for manual triggering
  pinMode(EXT_TRIGGER, INPUT_PULLUP);
  // periodically triggers photo shot
  pinMode(PHOTO_TRIGGER, OUTPUT);

  // start-up blink
  digitalWrite(LED_STATUS, HIGH);
  delay(250);
  digitalWrite(LED_STATUS, LOW);
}

void loop() {
  digitalWrite(PHOTO_TRIGGER, HIGH);
  delay(PHOTO_TRIGGER_MS);
 
  digitalWrite(PHOTO_TRIGGER, LOW);
  delay(PHOTO_TRIGGER_PERIOD_MS - PHOTO_TRIGGER_MS);
}
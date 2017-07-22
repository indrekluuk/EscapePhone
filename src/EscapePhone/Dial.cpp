//
// Created by indrek on 22.07.2017.
//

#include "Dial.h"
#include "Arduino.h"









void Dial::process() {
  if (pinStatusTimer > millis()) {
    pinStatusTimer = 0;
  }
  uint32_t time = millis() - pinStatusTimer;


  if (isDial) {
    if ((pinStatus == 1) && (time > DIAL_END_ms)) {
      isDial = false;
      if (pulseCount > 0) {
        addNumber(pulseCount == 10 ? 0 : pulseCount);
      }

    } else if (time > DIAL_PULSE_EDGE_ms) {
      if (pinStatus == 1) {
        isPulseCheck = true;
      } else {
        if (isPulseCheck) {
          pulseCount++;
        }
        isPulseCheck = false;
      }
    }

  } else {
    if ((pinStatus == 0) && (time > DIAL_START_ms)) {
      isDial = true;
      isPulseCheck = false;
      pulseCount = 0;
    }
  }


  int8_t currentPinStatus = digitalRead(dialPin);
  if (pinStatus != currentPinStatus) {
    pinStatus = currentPinStatus;
    pinStatusTimer = millis();
  }
}



void Dial::addNumber(uint8_t n) {
  Serial.println((int)n);

}





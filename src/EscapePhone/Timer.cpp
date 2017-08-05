//
// Created by indrek on 22.07.2017.
//

#include "Timer.h"
#include "Arduino.h"





bool Timer::isReady() {
  if (!ready) {
    uint32_t currentTime = millis();
    uint32_t startTime = endTime - time;

    if (startTime > endTime) { // is overflow
      if ((currentTime > endTime) && (currentTime < startTime)) {
        ready = true;
      }
    } else {
      if ((currentTime < startTime) || (currentTime > endTime)) {
        ready = true;
      }
    }
  }
  return ready;
}



void Timer::start() {
  endTime = millis() + time;
  ready = false;
}





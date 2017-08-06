//
// Created by indrek on 22.07.2017.
//

#include "Timer.h"
#include "Arduino.h"



Timer::Timer(uint32_t timerTime) {
  set(timerTime);
}


void Timer::set(uint32_t timerTime) {
  time = timerTime;
  stopped = true;
}

void Timer::start() {
  endTime = millis() + time;
  stopped = false;
}

void Timer::stop() {
  stopped = true;
}

bool Timer::isRunning() {
  return !stopped;
}

bool Timer::isReady() {
  if (!stopped) {
    uint32_t currentTime = millis();
    uint32_t startTime = endTime - time;

    if (startTime > endTime) { // is overflow
      if ((currentTime > endTime) && (currentTime < startTime)) {
        return true;
      }
    } else {
      if ((currentTime < startTime) || (currentTime > endTime)) {
        return true;
      }
    }
  }
  return false;
}








//
// Created by indrek on 21.07.2017.
//

#include "Ringer.h"
#include "Arduino.h"

Ringer::Ringer(uint8_t pin1, uint8_t pin2) : ringerPin1(pin1), ringerPin2(pin2) {
  pinMode(ringerPin1, OUTPUT);
  pinMode(ringerPin2, OUTPUT);
  digitalWrite(ringerPin1, LOW);
  digitalWrite(ringerPin2, LOW);
}

void Ringer::ring() {
  if (!timer) {
    timer = millis();
    isPause = false;
  }
}


void Ringer::stop() {
  timer = 0;
}


void Ringer::process() {
  // just in case if it loops around
  if (timer > millis()) timer = millis();

  if (timer) {
    uint32_t time = millis() - timer;

    if (isPause) {
      if (processPause(time)) {
        isPause = false;
        timer = millis();
      }
    } else {
      if (processRing(time)) {
        isPause = true;
        timer = millis();
      }
    }

  } else {
    digitalWrite(ringerPin1, LOW);
    digitalWrite(ringerPin2, LOW);
  }
}


bool Ringer::processPause(uint32_t time) {
  digitalWrite(ringerPin1, LOW);
  digitalWrite(ringerPin2, LOW);
  return time > PAUSE_TIME_ms;
}


bool Ringer::processRing(uint32_t time) {
  uint32_t periodTime = time % RING_PERIOD_ms;

  if (periodTime < (RING_PERIOD_ms / 2)) {
    digitalWrite(ringerPin2, LOW);
    if (periodTime < HIT_TIME_ms) {
      digitalWrite(ringerPin1, HIGH);
    } else {
      digitalWrite(ringerPin1, LOW);
    }

  } else {
    digitalWrite(ringerPin1, LOW);
    if ((periodTime - (RING_PERIOD_ms / 2)) < HIT_TIME_ms) {
      digitalWrite(ringerPin2, HIGH);
    } else {
      digitalWrite(ringerPin2, LOW);
    }
  }

  return time > RING_TIME_ms;
}

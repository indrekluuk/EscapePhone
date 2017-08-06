//
// Created by indrek on 21.07.2017.
//

#include "DeviceRinger.h"
#include "Arduino.h"

DeviceRinger::DeviceRinger(uint8_t pin1, uint8_t pin2) : ringerPin1(pin1), ringerPin2(pin2) {
  pinMode(ringerPin1, OUTPUT);
  pinMode(ringerPin2, OUTPUT);
  digitalWrite(ringerPin1, LOW);
  digitalWrite(ringerPin2, LOW);

  hitInterval.start();
}

void DeviceRinger::ring() {
  isRinging = true;
}


void DeviceRinger::stop() {
  isRinging = false;
}


void DeviceRinger::process() {
  if (isRinging) {
    if (pauseTimer.isRunning()) {
      ringerOff();
      if (pauseTimer.isReady()) {
        pauseTimer.stop();
      }
    } else {
      if (!ringTimer.isRunning()) {
        ringTimer.start();
      }
      processRing();
      if (ringTimer.isReady()) {
        ringTimer.stop();
        pauseTimer.start();
      }
    }

  } else {
    ringerOff();
    ringTimer.stop();
    pauseTimer.stop();
  }
}


void DeviceRinger::ringerOff() {
  digitalWrite(ringerPin1, LOW);
  digitalWrite(ringerPin2, LOW);
}


void DeviceRinger::processRing() {
  if (hitInterval.isReady()) {
    if (hitDirection) {
      digitalWrite(ringerPin1, HIGH);
    } else {
      digitalWrite(ringerPin2, HIGH);
    }
    hitDirection = !hitDirection;
    hitDuration.start();
    hitInterval.start();
  }

  if (hitDuration.isReady()) {
    ringerOff();
  }
}

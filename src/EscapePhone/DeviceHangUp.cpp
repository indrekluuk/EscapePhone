//
// Created by indrek on 6.08.2017.
//

#include "DeviceHangUp.h"
#include "Arduino.h"



DeviceHangUp::DeviceHangUp(uint8_t pin) : hangUpPin(pin) {
  digitalWrite(hangUpPin, HIGH);
}






bool DeviceHangUp::isHangUp() {
  return digitalRead(hangUpPin);
}


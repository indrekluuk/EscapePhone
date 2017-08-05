//
// Created by indrek on 22.07.2017.
//


#include "Arduino.h"



uint32_t test_millis = 0;

void testSetMillis(uint32_t m) {
  test_millis = m;
}

uint32_t millis() {
  return test_millis;
}





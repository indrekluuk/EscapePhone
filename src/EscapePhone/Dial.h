//
// Created by indrek on 22.07.2017.
//

#ifndef ESCAPEPHONE_DIAL_H
#define ESCAPEPHONE_DIAL_H

#include "stdint.h"


class Dial {


    static const uint32_t DIAL_START_ms = 150;
    static const uint32_t DIAL_PULSE_EDGE_ms = 15;
    static const uint32_t DIAL_END_ms = 150;



    uint8_t dialPin;

    bool isDial = false;
    int8_t pinStatus = 1;
    uint32_t pinStatusTimer = 0;
    bool isPulseCheck = false;
    uint8_t pulseCount = 0;

public:

    Dial(uint8_t pin) : dialPin(pin) {}
    void process();


private:
    void addNumber(uint8_t n);


};


#endif //ESCAPEPHONE_DIAL_H

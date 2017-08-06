//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_DEVICEDIALEDNUMBER_H
#define ESCAPEPHONE_DEVICEDIALEDNUMBER_H


#include <stdint.h>
#include "Timer.h"


class DeviceDialedNumber {

    static const uint32_t NUMBER_DIAL_END_ms = 3000;



    static const uint8_t MAX_NUMBER_LENGTH = 25;
    char dialedNumber[MAX_NUMBER_LENGTH + 1];
    Timer dialEndTimer = Timer(NUMBER_DIAL_END_ms);


public:
    DeviceDialedNumber();
    void reset();
    void addNumber(uint8_t number);
    void resetDialEndTimer();

    bool isNumberDialed();
    const char * getDialedNumber();
    bool isNumber(const char * checkNumber);
    uint8_t getDialedNumberLength();

    uint8_t getNumberLength(const char * n);

};


#endif //ESCAPEPHONE_DEVICEDIALEDNUMBER_H

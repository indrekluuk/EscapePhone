//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_DIALEDNUMBER_H
#define ESCAPEPHONE_DIALEDNUMBER_H


#include <stdint.h>
#include "Timer.h"


class DialedNumber {

    static const uint32_t NUMBER_DIAL_END_ms = 3000;



    static const uint8_t MAX_NUMBER_LENGTH = 15;
    char dialedNumber[MAX_NUMBER_LENGTH + 1];
    Timer dialEndTimer = Timer(NUMBER_DIAL_END_ms);


public:
    DialedNumber();
    void reset();
    void addNumber(uint8_t number);
    void resetDialEndTimer();

    bool isNumberDialed();
    const char * getDialedNumber();
    bool isNumber(const char * checkNumber);

    uint8_t getNumberLength(const char * n);

};


#endif //ESCAPEPHONE_DIALEDNUMBER_H

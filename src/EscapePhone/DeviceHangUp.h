//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_DEVICEHANGUP_H
#define ESCAPEPHONE_DEVICEHANGUP_H


#include <stdint.h>



class DeviceHangUp {

    uint8_t hangUpPin;



public:
    DeviceHangUp(uint8_t pin);
    bool isHangUp();

};


#endif //ESCAPEPHONE_DEVICEHANGUP_H

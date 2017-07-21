//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_ESCAPEPHONEMAIN_H
#define ESCAPEPHONE_ESCAPEPHONEMAIN_H

#include <stdint.h>
#include "Ringer.h"



class EscapePhoneMain {

    static const uint8_t PIN_RING_1 = 6;
    static const uint8_t PIN_RING_2 = 7;
    static const uint8_t PIN_HANG_UP = 8;
    static const uint8_t PIN_DIAL = 9;


    Ringer ringer = Ringer(PIN_RING_1, PIN_RING_2);

public:
    EscapePhoneMain();
    void run();


private:
    bool isHangUp();

};


#endif //ESCAPEPHONE_ESCAPEPHONEMAIN_H

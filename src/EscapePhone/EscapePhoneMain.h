//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_ESCAPEPHONEMAIN_H
#define ESCAPEPHONE_ESCAPEPHONEMAIN_H

#include <stdint.h>
#include "Mp3.h"
#include "Ringer.h"
#include "Dial.h"



class EscapePhoneMain {

    static const uint8_t PIN_MP3_TX = 2;
    static const uint8_t PIN_MP3_RX = 3;
    static const uint8_t PIN_RING_1 = 6;
    static const uint8_t PIN_RING_2 = 7;
    static const uint8_t PIN_HANG_UP = 8;
    static const uint8_t PIN_DIAL = 9;


    Mp3 mp3 = Mp3(PIN_MP3_RX, PIN_MP3_TX);
    Ringer ringer = Ringer(PIN_RING_1, PIN_RING_2);
    Dial dial = Dial(PIN_DIAL);

public:
    EscapePhoneMain();
    void run();


private:
    bool isHangUp();

};


#endif //ESCAPEPHONE_ESCAPEPHONEMAIN_H

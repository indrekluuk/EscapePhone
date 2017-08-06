//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_ESCAPEPHONEMAIN_H
#define ESCAPEPHONE_ESCAPEPHONEMAIN_H

#include <stdint.h>
#include "StateFactory.h"
#include "Devices.h"



class EscapePhoneMain {

    StateFactory stateFactory;
    Devices devices;

    StateBase * currentSate = nullptr;

public:
    EscapePhoneMain();
    void run();

};





#endif //ESCAPEPHONE_ESCAPEPHONEMAIN_H

//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEDIAL_H
#define ESCAPEPHONE_STATEDIAL_H



#include "StateBase.h"


class StateDial : public StateBase {


    bool isDialling = false;

public:
    StateDial(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};

    void reset();

    StateBase & processState() override;

};


#endif //ESCAPEPHONE_STATEDIAL_H

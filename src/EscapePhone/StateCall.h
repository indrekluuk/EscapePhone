//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATECALL_H
#define ESCAPEPHONE_STATECALL_H

#include "StateBase.h"
#include "DeviceMp3.h"


class StateCall : public StateBase {


public:
    StateCall(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};

    void init(DeviceMp3::Mp3 mp3);
    StateBase & process() override;

};


#endif //ESCAPEPHONE_STATECALL_H

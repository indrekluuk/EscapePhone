//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATECALL_H
#define ESCAPEPHONE_STATECALL_H

#include "StateBase.h"
#include "DeviceMp3.h"


class StateCall : public StateBase {


    DeviceMp3::Mp3 playMp3 = DeviceMp3::MP3_NONE;


public:
    StateCall(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};

    void setMp3(DeviceMp3::Mp3 mp3);

    StateBase & processState() override;

};


#endif //ESCAPEPHONE_STATECALL_H

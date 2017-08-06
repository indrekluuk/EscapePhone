//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATERINGING_H
#define ESCAPEPHONE_STATERINGING_H

#include "StateBase.h"
#include "DeviceMp3.h"
#include "Timer.h"


class StateRinging : public StateBase {


    DeviceMp3::Mp3 callMp3 = DeviceMp3::MP3_NONE;
    Timer giveUpTimer = Timer(30000);

public:
    StateRinging(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices) {};

    void init(DeviceMp3::Mp3 mp3);
    StateBase & process() override;

};



#endif //ESCAPEPHONE_STATERINGING_H

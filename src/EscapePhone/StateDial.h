//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_STATEDIAL_H
#define ESCAPEPHONE_STATEDIAL_H



#include "StateBase.h"
#include "PhoneBook.h"
#include "Timer.h"


class StateDial : public StateBase {


    PhoneBook phoneBook;
    Timer dialTimeout = Timer(30000);


public:
    StateDial(StateFactory & stateFactory, Devices & devices)
        : StateBase(stateFactory, devices),
          phoneBook(stateFactory) {};

    void init();
    StateBase & process() override;

};


#endif //ESCAPEPHONE_STATEDIAL_H

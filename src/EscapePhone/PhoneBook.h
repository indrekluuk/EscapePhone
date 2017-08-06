//
// Created by indrek on 6.08.2017.
//

#ifndef ESCAPEPHONE_PHONEBOOK_H
#define ESCAPEPHONE_PHONEBOOK_H

#include "DeviceDialedNumber.h"


class StateFactory;
class StateBase;

class PhoneBook {

    StateFactory & stateFactory;

public:
    PhoneBook(StateFactory & stateFactory)
        : stateFactory(stateFactory) {};

    StateBase & getStateForNumber(DeviceDialedNumber & dialedNumber);


};


#endif //ESCAPEPHONE_PHONEBOOK_H

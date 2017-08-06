//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_DEVICEMP3_H
#define ESCAPEPHONE_DEVICEMP3_H


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"



class DeviceMp3 {


    SoftwareSerial softwareSerial;
    DFRobotDFPlayerMini player;

    bool isPlaying = false;

public:
    DeviceMp3(uint8_t pinRx, uint8_t pinTx);

    void play();
    void stop();

};


#endif //ESCAPEPHONE_DEVICEMP3_H

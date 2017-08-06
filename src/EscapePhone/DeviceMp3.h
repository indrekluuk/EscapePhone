//
// Created by indrek on 21.07.2017.
//

#ifndef ESCAPEPHONE_DEVICEMP3_H
#define ESCAPEPHONE_DEVICEMP3_H


#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"



class DeviceMp3 {

public:
    enum Mp3{
        MP3_NONE = 0,
        MP3_DIAL_TONE = 1,
        MP3_BUSY_TONE = 2,
        MP3_RINGING_TONE = 3
    };
private:


    SoftwareSerial softwareSerial;
    DFRobotDFPlayerMini player;

    Mp3 playing = MP3_NONE;

public:
    DeviceMp3(uint8_t pinRx, uint8_t pinTx);

    void play(Mp3 mp3);
    void stop();

};


#endif //ESCAPEPHONE_DEVICEMP3_H

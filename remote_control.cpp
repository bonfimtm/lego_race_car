//
//  remote_control.cpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 29..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#include "remote_control.hpp"

RemoteControl::RemoteControl(unsigned int __receiverPin)
{
    this->pressedButton = RemoteControlButton::NONE;
    this->infraredReceiver = new IRrecv(__receiverPin);
}

void RemoteControl::setup(void)
{
    this->infraredReceiver->enableIRIn();
}

void RemoteControl::loop(void)
{
    decode_results results;

    if (this->infraredReceiver->decode(&results))
    {
        this->pressedButton = (RemoteControlButton)results.value;

        if ((unsigned long) RemoteControlButton::REPEATED != results.value)
        {
            Serial.println();
            Serial.print("Received remote control button: ");
            Serial.println(results.value, HEX);
        }

        this->infraredReceiver->resume();
    }
    else
    {
        this->pressedButton = RemoteControlButton::NONE;
    }
}

RemoteControlButton RemoteControl::getPressedButton(void) const
{
    return this->pressedButton;
}
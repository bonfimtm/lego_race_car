//
//  steering.cpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 30..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#include "steering.hpp"

Steering::Steering(
    unsigned int __pwmPin,
    unsigned int __dirPinA,
    unsigned int __dirPinB,
    RemoteControl *__remoteControl)
{
    this->pwmPin = __pwmPin;
    this->dirPinA = __dirPinA;
    this->dirPinB = __dirPinB;
    this->remoteControl = __remoteControl;
    this->angleRaw = 0;
}

void Steering::setup(void)
{
    pinMode(this->dirPinA, OUTPUT);
    pinMode(this->dirPinB, OUTPUT);
    pinMode(this->pwmPin, OUTPUT);

    digitalWrite(this->dirPinA, LOW);
    digitalWrite(this->dirPinB, HIGH);
    
    analogWrite(this->pwmPin, this->angleRaw);
}

void Steering::loop(void)
{
    if (RemoteControlButton::OK == this->remoteControl->getPressedButton())
    {
        this->setAngle(0);
    }
    else if (RemoteControlButton::LEFT == this->remoteControl->getPressedButton())
    {
        this->setAngle(-45);
    }

    else if (RemoteControlButton::RIGHT == this->remoteControl->getPressedButton())
    {
        this->setAngle(45);
    }

    analogWrite(this->pwmPin, this->angleRaw);
}

void Steering::setAngle(int angle)
{

    if (angle < -90 || angle > 90)
    {
        return;
    }

    if (angle > 0)
    {
        // Right
        digitalWrite(this->dirPinA, HIGH);
        digitalWrite(this->dirPinB, LOW);
    }
    else
    {
        // Left
        digitalWrite(this->dirPinA, LOW);
        digitalWrite(this->dirPinB, HIGH);
    }

    this->angleRaw = (int)(abs(angle) / 90.0 * 255);
}

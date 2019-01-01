//
//  powertrain.cpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 29..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#include "powertrain.hpp"

Powertrain::Powertrain(
    unsigned int __pwmPin,
    unsigned int __dirPinA,
    unsigned int __dirPinB,
    RemoteControl *__remoteControl)
{
    this->pwmPin = __pwmPin;
    this->dirPinA = __dirPinA;
    this->dirPinB = __dirPinB;
    this->remoteControl = __remoteControl;
    this->motorPower = Powertrain::MOTOR_POWER_MIN;
    this->direction = DrivingDirection::FORWARD;
}

void Powertrain::setup(void)
{
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(this->dirPinA, OUTPUT);
    pinMode(this->dirPinB, OUTPUT);
    pinMode(this->pwmPin, OUTPUT);

    digitalWrite(LED_BUILTIN, LOW);
    digitalWrite(this->dirPinA, HIGH);
    digitalWrite(this->dirPinB, LOW);

    analogWrite(this->pwmPin, this->motorPower);
}

void Powertrain::loop(void)
{
    if (RemoteControlButton::ONE == this->remoteControl->getPressedButton())
    {
        this->direction = DrivingDirection::FORWARD;
    }
    else if (RemoteControlButton::TWO == this->remoteControl->getPressedButton())
    {
        this->direction = DrivingDirection::REVERSE;
    }
    else if (RemoteControlButton::UP == this->remoteControl->getPressedButton())
    {
        this->motorPower = Powertrain::MOTOR_POWER_MAX;
    }
    else if (RemoteControlButton::DOWN == this->remoteControl->getPressedButton())
    {
        this->motorPower = Powertrain::MOTOR_POWER_MIN;
    }

    if (DrivingDirection::REVERSE == this->direction)
    {
        digitalWrite(this->dirPinA, LOW);
        digitalWrite(this->dirPinB, HIGH);
        digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
        digitalWrite(this->dirPinA, HIGH);
        digitalWrite(this->dirPinB, LOW);
        digitalWrite(LED_BUILTIN, LOW);
    }

    analogWrite(this->pwmPin, this->motorPower);
}

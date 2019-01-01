//
//  powertrain.hpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 29..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#ifndef powertrain_hpp
#define powertrain_hpp

#include "remote_control.hpp"

enum class DrivingDirection
{
  FORWARD = 1,
  REVERSE = -1,
};

class Powertrain
{
private:
  unsigned int pwmPin;
  unsigned int dirPinA;
  unsigned int dirPinB;
  RemoteControl *remoteControl;
  unsigned int motorPower;
  DrivingDirection direction;
  const static unsigned int MOTOR_POWER_MIN = 0;
  const static unsigned int MOTOR_POWER_MAX = 255;

public:
  Powertrain(
      unsigned int __pwmPin,
      unsigned int __dirPinA,
      unsigned int __dirPinB,
      RemoteControl *__remoteControl);
  void setup(void);
  void loop(void);
};

#endif /* powertrain_hpp */

//
//  steering.hpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 30..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#ifndef steering_hpp
#define steering_hpp

#include "remote_control.hpp"

class Steering
{
private:
  unsigned int pwmPin;
  unsigned int dirPinA;
  unsigned int dirPinB;
  RemoteControl *remoteControl;
  unsigned int angleRaw;

  const static int ANGLE_LEFT_MAX = -90;
  const static int ANGLE_CENTER = 0;
  const static int ANGLE_RIGHT_MAX = 90;

  const static int ANGLE_LEFT_MECH_MAX = -45;
  const static int ANGLE_RIGHT_MECH_MAX = 45;

  const static unsigned int ANGLE_RAW_MIN = 0;
  const static unsigned int ANGLE_RAW_MAX = 255;

public:
  Steering(
      unsigned int __pwmPin,
      unsigned int __dirPinA,
      unsigned int __dirPinB,
      RemoteControl *__remoteControl);
  void setup(void);
  void loop(void);
  void setAngle(int angle);
};

#endif /* steering_hpp */

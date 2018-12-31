//
//  remote_control.hpp
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 29..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#ifndef remote_control_hpp
#define remote_control_hpp

#include <IRremote.h>

enum class RemoteControlButton : unsigned long
{
  NONE = 0x0,
  OK = 0xFF02FD,
  RIGHT = 0xFFC23D,
  UP = 0xFF629D,
  LEFT = 0xFF22DD,
  DOWN = 0xFFA857,
  ONE = 0xFF6897,
  TWO = 0xFF9867,
};

class RemoteControl
{
private:
  RemoteControlButton pressedButton;
  IRrecv *infraredReceiver;

public:
  RemoteControl(unsigned int __receiverPin);
  void setup(void);
  void loop(void);
  RemoteControlButton getPressedButton(void) const;
};

#endif /* remote_control_hpp */

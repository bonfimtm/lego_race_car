//
//  lego_race_car.ino
//  lego_race_car
//
//  Created by Thiago Bonfim on 2018. 12. 29..
//  Copyright © 2018. Thiago Bonfim. All rights reserved.
//

#include "remote_control.hpp"
#include "powertrain.hpp"
#include "steering.hpp"

RemoteControl remoteControl(A0);
Powertrain powertrain(10, 9, 8, 7, &remoteControl);
Steering steering(6, 5, 4, &remoteControl);

// The setup function runs once when you press reset or power the board
void setup()
{
  remoteControl.setup();
  powertrain.setup();
  steering.setup();
}

// The loop function runs over and over again forever
void loop()
{
  remoteControl.loop();
  powertrain.loop();
  steering.loop();
}

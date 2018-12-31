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

#define SERIAL_BAUD_RATE 9600

#define REMOTE_CONTROL_RECEIVER_PIN A0

#define POWERTRAIN_PWM_PIN 10
#define POWERTRAIN_DIR_PIN_A 9
#define POWERTRAIN_DIR_PIN_B 8

#define STEERING_PWM_PIN 6
#define STEERING_DIR_PIN_A 5
#define STEERING_DIR_PIN_B 4

RemoteControl remoteControl(REMOTE_CONTROL_RECEIVER_PIN);
Powertrain powertrain(POWERTRAIN_PWM_PIN, POWERTRAIN_DIR_PIN_A, POWERTRAIN_DIR_PIN_B, &remoteControl);
Steering steering(STEERING_PWM_PIN, STEERING_DIR_PIN_A, STEERING_DIR_PIN_B, &remoteControl);

// The setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(SERIAL_BAUD_RATE);
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

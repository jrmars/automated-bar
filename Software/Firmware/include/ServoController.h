//
// Created by peter on 15/04/2019.
//

#ifndef AUTOMATED_BAR_SERVOCONTROLLER_H
#define AUTOMATED_BAR_SERVOCONTROLLER_H

#include <HX711/HX711.h>
#include "Drink.h"

// Constants
static const unsigned int kPinBase = 300;
static const unsigned int kFreq = 50;

static const unsigned int kRpiPwmPin = 18;
static const unsigned int kClockValue = 192;
static const unsigned int kMaxPwm = -1;
static const unsigned int kRangeValue = 2000;

static const unsigned int kPwmOn = 1000;
const unsigned int kPwmOff = 5;

const unsigned int kWaitInterval = 100;     /** Interval for testing weight of measure */


class ServoController {
public:
    ServoController();
    ~ServoController();

    void dispenseDrink(const Drink& drink);

private:
    HX711 scale;

    void activateServo(int pinNum, float target_weight);
};

#endif //AUTOMATED_BAR_SERVOCONTROLLER_H

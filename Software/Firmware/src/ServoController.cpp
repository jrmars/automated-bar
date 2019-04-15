//
// Created by peter on 15/04/2019.
//

#include <ServoController.h>
#include <stdexcept>
#include <wiringPi.h>
#include <pca9685.h>
#include <chrono>
#include <thread>

ServoController::ServoController() {
    // Setup ???
    const int pca_setup = pca9685Setup(kPinBase, 0x40, kFreq);

    if (pca_setup == -1) {
        throw std::runtime_error("Failed to setup GPIO for wiringPiPca9685");
    }

    pca9685PWMReset(pca_setup);
    pinMode(kRpiPwmPin, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(kClockValue);
    pwmSetRange(kRangeValue);

    // Setup ???
    scale = HX711();
}

ServoController::~ServoController() = default;

void ServoController::dispenseDrink(const Drink &drink) {
    activateServo(drink.servoPinNum, drink.targetWeight);
}

void ServoController::activateServo(int pinNum, float target_weight) {
    // Reset the scale and "start timer".
    scale.tare();
    auto begin = std::chrono::steady_clock::now();

    // Wait until weight is matched or max wait is reached.
    while(scale.read_trimmed_avg() <= target_weight){

        std::this_thread::sleep_for(std::chrono::milliseconds(kWaitInterval));

        // TODO: throw an exception if timeout reached. (compare now() and begin.)
    }

    pwmWrite(kPinBase + pinNum, kPwmOn);


}


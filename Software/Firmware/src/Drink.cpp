#include <utility>

//
// Created by peter on 15/04/2019.
//

#include "Drink.h"

/**
 * Conctructor.
 *
 * @param name - the name of the drink
 * @param servoPin - the pin of the servo for the drink
 * @param targetWeight - the target weight for a measure of the drink.
 */
Drink::Drink(std::string name, int servoPin, float targetWeight) :
name(std::move(name)), servoPinNum(servoPin), targetWeight(targetWeight) {}


//
// Created by peter on 15/04/2019.
//

#ifndef AUTOMATED_BAR_REVISEDDRINKSERVER_H
#define AUTOMATED_BAR_REVISEDDRINKSERVER_H

#include "DrinkStore.h"
#include "ServoController.h"

#include <HX711/HX711.h>

class RevisedDrinkServer {
public:
    RevisedDrinkServer();
    ~RevisedDrinkServer();


private:
    DrinkStore drinkStore;
    ServoController servoController;
};

#endif //AUTOMATED_BAR_REVISEDDRINKSERVER_H

//
// Created by peter on 15/04/2019.
//

#include "RevisedDrinkServer.h"

RevisedDrinkServer::RevisedDrinkServer() {
    drinkStore = DrinkStore();
    servoController = ServoController();
}

RevisedDrinkServer::~RevisedDrinkServer() = default;

// TODO: Impl. - look at PyDrinkServer and change to use ServoController + DrinkStore instead
//  e.g. using "name" from HTTP request, get Drink from drinkStore and send to ServoController.

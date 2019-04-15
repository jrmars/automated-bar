#include "DrinkStore.h"
#include "Drink.h"

#include <map>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdexcept>


DrinkStore::DrinkStore() {

    // Initialize the drink map
    this->kDrinks = {
            //TODO: fix the drink weights here - add all the database.py drinks here (or in
            //  a file which you read in here.
            //TODO: can break this into a separate drink map and a mixer map if you want.
            {"Rum", Drink("Rum", 0, 0.94)},
            {"Vodka", Drink("Vodka", 1, 0.97)},
            {"Buckfast", Drink("Buckfast", 2, 0.98)},
            {"Gin", Drink("Plymouth Gin", 3, 0.94)},
            {"Coke", Drink("Coke", 4, 1.045)},
            {"Lemonade", Drink("Lemonade", 5, 1.0)},
            {"Irn-Bru", Drink("Irn-Bru", 6, 1.05)},
            {"Tonic", Drink("Tonic", 7, 1.031)}
    };
}

DrinkStore::~DrinkStore() = default;

/**
 * Returns a Drink object representing the drink with the given
 * name.
 *
 * @param spiritName - the name of the drink to retrieve
 * @return a Drink pointer representing the drink.
 * @throws a std::invalid_argument  exception if there was no
 * drink with the given name.
 */
Drink* DrinkStore::getDrink(const std::string& drinkName) {
    auto it = kDrinks.find(drinkName);

    if (it != kDrinks.end()) {
        return &(it->second);
    }
    else {
        throw std::invalid_argument("Unsupported drink:" + drinkName);
    }
}

int DrinkStore::addDrink(const Drink& drink) {
    kDrinks.insert(std::pair<std::string, Drink>(drink.name, drink));
}

int DrinkStore::removeDrink(const std::string& drink){
    kDrinks.erase(drink);
}


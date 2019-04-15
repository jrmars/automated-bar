//
// Created by peter on 15/04/2019.
//

#ifndef AUTOMATED_BAR_DRINKSTORE_H
#define AUTOMATED_BAR_DRINKSTORE_H

#include <map>
#include <stdio.h>
#include "Drink.h"

class DrinkStore {
public:
    //Constructors and Destructors
    DrinkStore();
    ~DrinkStore();

    //Public functions - get/add/remove
    Drink* getDrink(const std::string& drinkName);
    int addDrink(const Drink& drink);  //Arconst gs co&uld be either a Drink or the required fields.
    int removeDrink(const std::string& drink);
private:
    //Private variables - the actual map of drinks.
    std::map<std::string, Drink> kDrinks;
};

#endif //AUTOMATED_BAR_DRINKSTORE_H

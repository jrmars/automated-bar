#pragma once

#include <map>

#include "Drinks.h"

namespace mai {

    // [peter] Consider having a map of Drink structs keyed on name, i.e. a map<std::string, Drink>,
    // then have methods "getDrink", "addDrink" and "removeDrink" here - the caller then get the
    // fields they want from the struct e.g. drinksConfig.getDrink("SomeDrink").getPosition().
    // See also comments in Drinks.h.
    class DrinksConfig {
    public:

        DrinksConfig();

        void set_position(const Drinks::Position drink_pos, const Drinks::Type drink_type);

        Drinks::Type get_drink(const Drinks::Position drink_pos);
        Drinks::Position get_position(const Drinks::Type drink_type);

    private:
        std::map<Drinks::Type, Drinks::Position> m_drinks_map;
         
    };

}
#pragma once

#include <string>

namespace mai {

    // [peter] This seems a bit convoluted - in general its a good idea to map
    // things against a key which you can immediately use to look them up e.g. a string.
    // Consider using a "Drink" struct with the fields you need and mapping to the
    // string name in the DrinksConfig class. (see: DrinkConfig.h comment)
    // Example constructor: Drink(std::string name, int servoNum);
  namespace Drinks {

      enum class Type {
        BUCKFAST,
        COKE,
        GIN,
        IRNBRU,
        LEMONADE,
        RUM,
        TONIC,
        VODKA
      };

      class Position {
      public:
        Position(const unsigned int pin_num) : m_pin_num(pin_num) {}
      
        bool operator==(const Position &rhs) const {
          return m_pin_num == rhs.m_pin_num;
        }
        operator int() const { return m_pin_num; }

      private:
        unsigned int m_pin_num;
      };

      // [peter] This is going to break if you replace drinks - this is basically
      // hard-coding the available drinks.
      // [peter] Also small point - inconsistent indentation size - use a single indentation
      // size for all lines, e.g. 4 spaces or 2 spaces.
      static Type resolve_drink(const std::string &drink) {
        if (drink == "buckfast")
          return Drinks::Type::BUCKFAST;
        else if (drink == "coke")
          return Drinks::Type::COKE;
        else if (drink == "gin")
          return Drinks::Type::GIN;
        else if (drink == "irnbru")
          return Drinks::Type::IRNBRU;
        else if (drink == "lemonade")
          return Drinks::Type::LEMONADE;
        else if (drink == "rum")
          return Drinks::Type::RUM;
        else if (drink == "tonic")
          return Drinks::Type::TONIC;
        else if (drink == "vodka")
          return Drinks::Type::VODKA;
        else
          throw std::runtime_error("Could not resolve drink type: " + drink);
      }

  }

}
#include "DrinkServer.h"

DrinkServer::DrinkServer(const mai::DrinksConfig &drinks_config) {
    for (const auto& drink: drinks_config.m_drinks_map) {
        const mai::Drinks::Type drink_type = drink.first;
        const mai::Drinks::Position drink_pos = drink.second;
        servo_map[drink.first] = ServoHandler(static_cast<int>(drink_pos));
    }
}

DrinkServer::Status DrinkServer::weight_match(HX711 scale, const float target_weight){

    while(scale.read_trimmed_avg() <= target_weight){
        // Wait until weight is matched
    }
    return DrinkServer::Status::DISPENSE_SUCCESS;
}


DrinkServer::Status DrinkServer::dispense_drink(const mai::Drinks::Type drink_type, const float weight_gm) {
    /* @TODO */
    
    ServoHandler& servo = servo_map.find(drink_type)->second;

    scale.tare();

    if (servo.activate() != ServoHandler::ServoStatus::ACTION_SUCCESS){  
        throw std::runtime_error("Could not activate servo ");
    }

    DrinkServer::Status weight_status = weight_match(scale, weight_gm);

    if (servo.deactivate() != ServoHandler::ServoStatus::ACTION_SUCCESS){  
        throw std::runtime_error("Could not deactivate servo ");
    }

    return DrinkServer::Status::DISPENSE_SUCCESS;
}



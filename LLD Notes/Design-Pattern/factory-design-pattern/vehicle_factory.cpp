#include "vehicle_factory.hpp"
#include <iostream>

Vehicle *VehicleFactory::getVehicle(std::string vehicleType)
{

    Vehicle *createdVehicle = NULL;
    if (vehicleType == "car")
        createdVehicle = new Car();
    else if (vehicleType == "bike")
        createdVehicle = new Car();

    return createdVehicle;
}
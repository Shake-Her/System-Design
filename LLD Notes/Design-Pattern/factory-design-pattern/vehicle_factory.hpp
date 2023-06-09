#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include "car.hpp"
#include "bike.hpp"
#include <iostream>

class VehicleFactory
{
public:
    static Vehicle *getVehicle(std::string vehicleType);
};
#endif
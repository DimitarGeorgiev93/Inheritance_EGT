#pragma once
#include "Vehicle.h"
class LandVehicle :
    virtual public Vehicle
{
public:
    LandVehicle(const std::string, const std::string, const float, const float, const float, const unsigned short);
    ~LandVehicle();

    float GetTime(const float) const;

    //void printInfo() const override;
protected:
    float MaxSpeed;
    unsigned short HorsePower;
};


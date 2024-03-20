#pragma once
#include "Vehicle.h"

class WaterVehicle :
    virtual public Vehicle
{
public:
    WaterVehicle(const std::string, const std::string, const float, const float, const float, const float);
    ~WaterVehicle();

    float GetSpeedUpStream(const float) const;
    float GetSpeedDownStream(const float) const;

    float GetTimeUpStream(const float, const float) const;
    float GetTimeDownStream(const float, const float) const;

   // void printInfo() const override;
protected:
    float WaterVolume;
    float MaxKnots;
};


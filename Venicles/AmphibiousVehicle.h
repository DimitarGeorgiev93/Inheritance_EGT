#pragma once
#include "WaterVehicle.h"
#include "LandVehicle.h"


class AmphibiousVehicle :
     public WaterVehicle, public LandVehicle
{
public:
    AmphibiousVehicle(const std::string, const std::string, const float, const float, const float, const unsigned short, const float, const float);
    ~AmphibiousVehicle();

    bool CanTheVehiclePassTheDistanceUnderAnHour(const float, const float, const float, const float) const;

private:

};


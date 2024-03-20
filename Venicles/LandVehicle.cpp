#include "LandVehicle.h"

LandVehicle::LandVehicle(const std::string NewVehicleBrand, const std::string NewVehicleModel, const float NewHeight,
	const float NewWeight, const float NewMaxSpeed, const unsigned short NewHorsePower)
	: Vehicle(NewVehicleBrand, NewVehicleModel, NewHeight, NewWeight)
{
	MaxSpeed = NewMaxSpeed;
	HorsePower = NewHorsePower;
}



LandVehicle::~LandVehicle()
{
}

float LandVehicle::GetTime(const float Distance) const
{
	return Distance / MaxSpeed;
}


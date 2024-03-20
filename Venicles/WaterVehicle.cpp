#include "WaterVehicle.h"

WaterVehicle::WaterVehicle(const std::string NewVehicleBrand, const std::string NewVehicleModel, const float NewHeight,
	const float NewWeight, const float NewWaterVolume, const float NewMaxKnots)
	: Vehicle(NewVehicleBrand, NewVehicleModel, NewHeight, NewWeight)
{
	WaterVolume = NewWaterVolume;
	MaxKnots = NewMaxKnots;
}

WaterVehicle::~WaterVehicle()
{
}

float WaterVehicle::GetSpeedUpStream(const float StreamSpeed) const
{
	return MaxKnots - StreamSpeed;
}

float WaterVehicle::GetSpeedDownStream(const float StreamSpeed) const
{
	return MaxKnots + StreamSpeed;
}

float WaterVehicle::GetTimeUpStream(const float Distance, const float StreamSpeed) const
{
	return Distance / (MaxKnots - StreamSpeed);
}

float WaterVehicle::GetTimeDownStream(const float Distance, const float StreamSpeed) const
{
	return Distance / (MaxKnots + StreamSpeed);
}

//void WaterVehicle::printInfo() const
//{
//	Vehicle::printInfo();
//	std::cout << "\nWaterVolume: " << WaterVolume << "\nMax Knots: " << MaxKnots;
//}

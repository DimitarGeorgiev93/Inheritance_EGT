#include "AmphibiousVehicle.h"

AmphibiousVehicle::AmphibiousVehicle(const std::string NewVehicleBrand, const std::string NewVehicleModel, const float NewHeight,
	const float NewWeight, const float NewMaxSpeed, const unsigned short NewHorsePower, const float NewWaterVolume, const float NewMaxKnots)
	: WaterVehicle(NewVehicleBrand, NewVehicleModel, NewHeight, NewWeight, NewWaterVolume, NewMaxKnots),
	LandVehicle(NewVehicleBrand, NewVehicleModel, NewHeight, NewWeight, NewMaxSpeed, NewHorsePower), 
	Vehicle(NewVehicleBrand, NewVehicleModel, NewHeight, NewWeight)
{

}

AmphibiousVehicle::~AmphibiousVehicle()
{
}

bool AmphibiousVehicle::CanTheVehiclePassTheDistanceUnderAnHour(const float LandDisntance, const float BridgeHeight, const float WaterDistanceUpStream, const float StreamSpeed) const
{
	if (!Vehicle::CanPassUnderBridge(BridgeHeight))
	{
		return false;
	}	
	float totalTime = LandVehicle::GetTime(LandDisntance) + (WaterDistanceUpStream / WaterVehicle::GetSpeedUpStream( StreamSpeed));

	if (totalTime > 60)
	{
		return false;
	}

	return true;
}

//void AmphibiousVehicle::printInfo() const
//{
//	//Vehicle::printInfo();
//	WaterVehicle::printInfo();
//	LandVehicle::printInfo();
//}

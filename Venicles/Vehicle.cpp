#include "Vehicle.h"

Vehicle::Vehicle(const std::string NewVehicleBrand, const std::string NewVehicleModel, const float NewHeight, const float NewWeight)
	: VehicleBrand(NewVehicleBrand), VehicleModel(NewVehicleModel)
{
	Height = NewHeight;
	Weigth = NewWeight;
}

Vehicle::~Vehicle()
{
}

bool Vehicle::CanPassUnderBridge(const float BridgeHeight) const
{
	if (Height >= BridgeHeight) {
		return false;
	}
	
	return true;
}

bool Vehicle::CanPassOverBridge(const float BridgeWeight) const
{
	
	if (Weigth >= BridgeWeight) {
		return false;
	}

	return true;
}

//void Vehicle::printInfo() const
//{
//	std::cout << "\nBrand: " << VehicleBrand << "\nModel : " << VehicleModel << "\nHeight : " << Height << "\nWeight " << Weigth;
//}

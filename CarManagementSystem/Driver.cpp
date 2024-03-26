#include "Driver.h"

Driver::Driver(std::string name, unsigned short age, bool license , Car* car )
{
	DriverName = name;
	DriverAge = age;
	HasDriverLicense = license;
	RentedCar = car;

	StorageTires = nullptr;
	RentedACarFromHere = nullptr;
}

Driver::~Driver()
{
}


void Driver::RentACar(CarRentalAgency* Agency)
{
	if (Agency == nullptr)
	{
		return;
	}

	RentedCar = Agency->RentOutACar(DriverName);

	if (RentedCar != nullptr)
	{
		RentedACarFromHere = const_cast<CarRentalAgency*> (Agency);
		RentedCarHistory.push_back(RentedCar);
	}
}

void Driver::RentSpecificCar(const CarRentalAgency* Agency, const unsigned short CarId)
{
	if (!Agency)
	{
		return;
	}
	RentedCar = const_cast<CarRentalAgency*>(Agency)->RentOutSpecificCar(CarId, DriverName);

	if (RentedCar != nullptr)
	{
		RentedACarFromHere = const_cast<CarRentalAgency*> (Agency);
		RentedCarHistory.push_back(RentedCar);
	}
	//std::cout << RentedCar->GetCarBrand() << std::endl;
}

void Driver::ReturnRentedcar()
{
	if (RentedACarFromHere == nullptr)
	{
		return;
	}
	//std::cout << "Not rsdadasdenting a car atm" << std::endl;
	RentedACarFromHere->CustomerReturnsACar(dynamic_cast<RentalCar*>(RentedCar));
}

void Driver::PrintInfo() const
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Name: " << DriverName << std::endl;
	std::cout << "Age: " << DriverAge << std::endl;
	std::cout << "Driving license: ";
	switch (HasDriverLicense) 
	{
	case 0:
		std::cout << "True" << std::endl;
		break;
	case 1:
		std::cout << "True" << std::endl;
		break;
	}
	std::cout << "Rented car: " << std::endl;
	if (RentedCar)
	{
		RentedCar->PrintInfo();
	}
	else
	{
		std::cout << "Not renting a car at this moment" << std::endl;
	}
}

void Driver::DriveCar() const
{
	if (!RentedCar)
	{	
		std::cout << "No rented car" << std::endl;
		return;
	}
	RentedCar->StartEngine();
}

void Driver::StopCar() const
{
	RentedCar->StopEngine();
}

void Driver::PutTiresOnCar()
{
	if (RentedCar->DoesItHaveTires())
	{
		RentedCar->ChangeTires(StorageTires);
	}
	else
	{
		RentedCar->PutTiresOn(StorageTires);
		StorageTires = nullptr;
	}
}

void Driver::BuyTires(const Tire* NewTires)
{
	if (!NewTires)
	{
		std::cout << "No rented car" << std::endl;
		return;
	}
	else
	{
		StorageTires = const_cast<Tire*>(NewTires);
	}

}

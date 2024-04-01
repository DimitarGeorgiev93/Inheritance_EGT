#include "RentalCar.h"

RentalCar::RentalCar(const CarBrand NewCarBrand,unsigned short NewID, const std::string NewRentalLocation, unsigned short NewRentPerMonth, const Tire* NewTires)
	:Car(NewCarBrand, NewTires), ID(NewID), RentalLocation(NewRentalLocation)
{
	RentPerMonth = NewRentPerMonth;
	IsItRented = false;
}

RentalCar::~RentalCar()
{
}

bool RentalCar::GetRentStatus() const
{
	return IsItRented;
}

void RentalCar::ChangeRentPerMonth(const unsigned short NewRentPerMonth)
{
	RentPerMonth = NewRentPerMonth;
}

void RentalCar::PrintInfo() const
{
	std::cout << "Car ID: " << ID << std::endl;
	Car::PrintInfo();
	std::cout << "Price per month: " << RentPerMonth << std::endl;
}

unsigned short RentalCar::GetID() const
{
	return ID;
}

std::string RentalCar::GetRentalLocation() const
{
	return RentalLocation;
}

void RentalCar::ChangeRentedStatus()
{
	if (IsItRented)
	{
		//std::cout << "Changing rent status to false" << std::endl;
		IsItRented = false;
	}
	else
	{
		//std::cout << "Changing rent status to true" << std::endl;
		IsItRented = true;
	}
}

unsigned short RentalCar::GetRentPrice() const
{
	return RentPerMonth;
}

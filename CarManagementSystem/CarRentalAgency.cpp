#include "CarRentalAgency.h"

CarRentalAgency::CarRentalAgency(std::string NewAgencyName, std::string NewAgencyLocation)
{
	AgencyLocation = NewAgencyLocation;
	AgencyName = NewAgencyName;

	AgencyLocations.push_back(new RentalLocation("Sofia",AgencyName+"-Sofia"));
	AgencyLocations.push_back(new RentalLocation("Burgas", AgencyName + "-Burgas"));
	AgencyLocations.push_back(new RentalLocation("Plovdiv", AgencyName + "-Plovdiv"));

	int ID = 1;
	for (auto var : AgencyLocations)
	{
		AddCarToLocation(var, ID);
	}

}

CarRentalAgency::~CarRentalAgency()
{
	
	for (RentalLocation* tempAgency : AgencyLocations)
	{
		RentalLocation* tempEmp = tempAgency;

		if (tempEmp != nullptr)
		{
			delete tempEmp;
		}
		tempEmp = nullptr;
	}
}

unsigned short CarRentalAgency::GetNumberOfCarsForRent() const
{
	int TotalNumberOfCarsForRent = 0;
	for (auto var : AgencyLocations)
	{
		TotalNumberOfCarsForRent += var->GetNumberOfCarsForRent();
	}
	return TotalNumberOfCarsForRent;
}

void CarRentalAgency::ListAvaiableCarsForRent() const
{
	for (auto var : AgencyLocations)
	{
		var->ListAvaiableCarsForRent();
	}
}

Car* CarRentalAgency::RentOutACar(const std::string)
{
	return nullptr;
}


void CarRentalAgency::CustomerReturnsACar(RentalCar* ReturnedCar)
{
	if (!ReturnedCar)
	{
		std::cout << "Invalid entry" << std::endl;
		return;
	}
	//RentalCar* temp = const_cast<RentalCar*> (ReturnedCar);
	ReturnedCar->ChangeRentedStatus();

}

unsigned int CarRentalAgency::CalculateProfitFromRentedCars() const
{
	int TotalNumberOfCarsForRent = 0;
	for (auto var : AgencyLocations)
	{
		TotalNumberOfCarsForRent += var->CalculateProfitFromRentedCars();
	}
	return TotalNumberOfCarsForRent;
}

void CarRentalAgency::PrintMostPopularCarBrand() const
{
	for (auto var : AgencyLocations)
	{
		var->PrintMostPopularCarBrand();
	}
}

void CarRentalAgency::PrintPopularityList() const
{
	for (auto var : AgencyLocations)
	{
		var->PrintPopularityList();
	}
}

void CarRentalAgency::PrintLogBook() const
{
	for (auto var : AgencyLocations)
	{
		var->PrintLogBook();
	}
}

void CarRentalAgency::AddCarToLocation( RentalLocation* const Location, int& CarId)
{
	if (Location == nullptr)
	{
		std::cout << "No such location" << std::endl;
		return;
	}
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		Location->AddCar(new RentalCar(CarBrand(rand() % 3), CarId++, AgencyLocation, rand() % 1000 + 500));
	}
}

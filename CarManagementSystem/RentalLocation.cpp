#include "RentalLocation.h"

RentalLocation::RentalLocation(const std::string NewLocation, const std::string NewLocationName)
{
	LocationName = NewLocationName;
	Location = NewLocation;
}

RentalLocation::~RentalLocation()
{
	std::unordered_map<unsigned short, RentalCar*>::iterator itr = RentalCars.begin();
	while (itr != RentalCars.end())
	{
		Car* tempEmp = itr->second;
		RentalCars.erase(itr++);

		if (tempEmp != nullptr)
		{
			delete tempEmp;
		}
		tempEmp = nullptr;
	}

	for (RentalTransaction* var : RentLogBook)
	{
		RentalTransaction* tempEmp = var;

		if (tempEmp != nullptr)
		{
			delete tempEmp;
		}
		tempEmp = nullptr;
	}
}

void RentalLocation::AddCar(const RentalCar* NewRentalCar)
{
	if (NewRentalCar == nullptr)
	{
		std::cout << "No car to be added" << std::endl;
		return;
	}
	RentalCars.emplace(NewRentalCar->GetID(), NewRentalCar);
}

unsigned short RentalLocation::GetNumberOfCarsForRent() const
{
	return RentalCars.size();
}

void RentalLocation::PrintMostPopularCarBrand() const
{
	std::cout << ".........................................." << std::endl;
	std::cout << LocationName << std::endl;
	std::cout << ".........................................." << std::endl;
	std::pair<CarBrand, unsigned short > MostPopularCar;
	MostPopularCar.second = 0;
	for (auto car : CarPopularityList)
	{
		if (MostPopularCar.second < car.second)
		{
			MostPopularCar = car;
		}
	}

	if (MostPopularCar.second == 0)
	{
		std::cout << "No rents yet" << std::endl;
	}
	else
	{
		std::cout << "Most popular brand: ";
		switch (MostPopularCar.first) {
		case 0:
			std::cout << "Opel";
			break;
		case 1:
			std::cout << "Kia";
			break;
		case 2:
			std::cout << "Mazda";
			break;
		}
		std::cout << " Total rents: " << MostPopularCar.second << std::endl;
	}
}
void RentalLocation::PrintPopularityList() const
{
	std::cout << ".........................................." << std::endl;
	std::cout << LocationName << std::endl;
	std::cout << ".........................................." << std::endl;
	for (auto car : CarPopularityList)
	{
		std::cout << "Brand: ";
		switch (car.first) {
		case 0:
			std::cout << "Opel";
			break;
		case 1:
			std::cout << "Kia";
			break;
		case 2:
			std::cout << "Mazda";
			break;
		}
		std::cout << " Total rents: " << car.second << std::endl;
	}
}
unsigned int RentalLocation::CalculateProfitFromRentedCars() const
{
	int totalSum = 0;
	for (auto car : RentalCars)
	{
		if (car.second->GetRentStatus())
		{
			totalSum += car.second->GetRentPrice();
		}
	}
	std::cout << "Rent per month: " << totalSum << std::endl;

	return totalSum;
}

void RentalLocation::ListAvaiableCarsForRent() const
{
	std::cout << ".........................................." << std::endl;
	std::cout << LocationName << std::endl;
	std::cout << ".........................................." << std::endl;
	for (auto car : RentalCars)
	{
		if (!car.second->GetRentStatus())
		{
			car.second->PrintInfo();
		}
		std::cout << ".........................................." << std::endl;
	}
}

void RentalLocation::PrintLogBook() const
{
	std::cout << ".........................................." << std::endl;
	std::cout << LocationName << std::endl;
	std::cout << ".........................................." << std::endl;
	for (auto transaction : RentLogBook)
	{
		std::cout << "Provider: " << transaction->ProviderAgencyName << std::endl;
		std::cout << "Buyer: " << transaction->CustomerName << std::endl;
		std::cout << "Venicle ID: " << transaction->VenicleID << std::endl;
		std::cout << "Price: " << transaction->RentalPrice << std::endl;
	}
}

Car* RentalLocation::RentOutACar(const std::string DriverName)
{
	for (std::pair<unsigned short, RentalCar*> car : RentalCars)
	{
		if (!car.second->GetRentStatus())
		{
			std::cout << "Renting out car id " << car.first << std::endl;
			car.second->ChangeRentedStatus();

			if (CarPopularityList.find(car.second->GetCarBrand()) == CarPopularityList.end())
			{
				std::cout << ".........................................." << std::endl;
				CarPopularityList.emplace(car.second->GetCarBrand(), 1);
			}
			else
			{
				CarPopularityList.find(car.second->GetCarBrand())->second++;
			}

			RentalTransaction* NewTransaction = new RentalTransaction;
			NewTransaction->CustomerName = DriverName;
			NewTransaction->ProviderAgencyName = LocationName;
			NewTransaction->VenicleID = car.second->GetID();
			NewTransaction->RentalPrice = car.second->GetRentPrice();

			RentLogBook.push_back(NewTransaction);

			return car.second;
			//car.second->PrintInfo();
		}
		//std::cout << ".........................................." << std::endl;
	}
	std::cout << "No cars to rent out, sorry" << std::endl;
	return nullptr;
}

Car* RentalLocation::RentOutSpecificCar(const unsigned short CarId, const std::string DriverName)
{
	if (RentalCars.find(CarId) == RentalCars.end())
	{
		std::cout << "No car with that ID, sorry" << std::endl;
		return nullptr;
	}
	if (RentalCars.find(CarId)->second->GetRentStatus())
	{
		std::cout << "That car is rented out, sorry" << std::endl;
		return nullptr;
	}

	if (CarPopularityList.find(RentalCars.find(CarId)->second->GetCarBrand()) == CarPopularityList.end())
	{
		CarPopularityList.emplace(RentalCars.find(CarId)->second->GetCarBrand(), 1);
	}
	else
	{
		//std::cout << "......asdasdasdasd......................." << std::endl;
		CarPopularityList.find(RentalCars.find(CarId)->second->GetCarBrand())->second++;
	}

	std::cout << "Rented out car id " << RentalCars.at(CarId)->GetID() << std::endl;
	RentalCars.at(CarId)->ChangeRentedStatus();

	RentalTransaction* NewTransaction = new RentalTransaction;
	NewTransaction->CustomerName = DriverName;
	NewTransaction->ProviderAgencyName = LocationName;
	NewTransaction->VenicleID = CarId;
	NewTransaction->RentalPrice = RentalCars.at(CarId)->GetRentPrice();

	RentLogBook.push_back(NewTransaction);

	return RentalCars.at(CarId);
}
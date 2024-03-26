#include "CarRentalAgency.h"

CarRentalAgency::CarRentalAgency(std::string NewAgencyName, std::string NewAgencyLocation)
{
	AgencyLocation = NewAgencyLocation;
	AgencyName = NewAgencyName;

	RentalCar* temp;
	srand(time(NULL));
	for (int i = 1; i < 6; i++) {

		temp = new RentalCar (CarBrand(rand()%3 ), i , rand()%1000 + 500 );
		Sleep(1000);
		RentalCars.emplace(i, temp);
		temp = nullptr;
	}
}

CarRentalAgency::~CarRentalAgency()
{
	std::map<unsigned short, RentalCar*>::iterator itr = RentalCars.begin();
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
}

int CarRentalAgency::GetNumberOfCarsForRent() const
{
	return RentalCars.size();
}

void CarRentalAgency::ListAvaiableCarsForRent() const
{
	for (auto car : RentalCars)
	{
		if (!car.second->GetRentStatus())
		{
			car.second->PrintInfo();
		}
		std::cout << ".........................................." << std::endl;
	}
}

Car* CarRentalAgency::RentOutACar(const std::string DriverName)
{
	for (std::pair<unsigned short, RentalCar*> car : RentalCars)
	{
		if (!car.second->GetRentStatus())
		{
			std::cout << "Renting out car id "<< car.first<< std::endl;
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
			RentalTransaction NewTransaction;
			NewTransaction.CustomerName = DriverName;
			NewTransaction.ProviderAgencyName = AgencyName;
			NewTransaction.VenicleID = car.second->GetID();
			NewTransaction.RentalPrice = car.second->GetRentPrice();

			RentLogBook.push_back(NewTransaction);

			return car.second;
			//car.second->PrintInfo();
		}
		//std::cout << ".........................................." << std::endl;
	}
	std::cout << "No cars to rent out, sorry" << std::endl;
	return nullptr;
}

Car* CarRentalAgency::RentOutSpecificCar(const unsigned short CarId, const std::string DriverName)
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

	RentalTransaction NewTransaction;
	NewTransaction.CustomerName = DriverName;
	NewTransaction.ProviderAgencyName = AgencyName;
	NewTransaction.VenicleID = CarId;
	NewTransaction.RentalPrice = RentalCars.at(CarId)->GetRentPrice();

	RentLogBook.push_back(NewTransaction);

	return RentalCars.at(CarId);
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

void CarRentalAgency::CalculateProfitFromRentedCars() const
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
}

void CarRentalAgency::PrintMostPopularCarBrand() const
{
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

void CarRentalAgency::PrintPopularityList() const
{
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

void CarRentalAgency::PrintLogBook() const
{
	for (auto transaction : RentLogBook)
	{
		std::cout << "Provider: " << transaction.ProviderAgencyName << std::endl;
		std::cout << "Buyer: " << transaction.CustomerName << std::endl;
		std::cout << "Venicle ID: " << transaction.VenicleID << std::endl;
		std::cout << "Price: " << transaction.RentalPrice << std::endl;
	}
}

//void CarRentalAgency::AddCarBrandToCPL(CarBrand Brand)
//{
//	CarPopularityList.emplace(Brand, 1);
//}

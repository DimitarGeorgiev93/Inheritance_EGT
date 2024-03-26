#pragma once
#include "RentalCar.h"
#include "map"
#include <windows.h>
#include "RentalTransaction.h"
#include "RentalLocation.h"

class CarRentalAgency
{
public:
	CarRentalAgency(std::string, std::string);
	~CarRentalAgency();

	int GetNumberOfCarsForRent() const;

	void ListAvaiableCarsForRent() const;

	Car* RentOutACar(const std::string);
	Car* RentOutSpecificCar(const unsigned short, const std::string);
	void CustomerReturnsACar(RentalCar*);

	void CalculateProfitFromRentedCars() const;

	void PrintMostPopularCarBrand() const;

	void PrintPopularityList() const;

	void PrintLogBook() const;

private:

	//void AddCarBrandToCPL(CarBrand);
	std::vector<RentalLocation> AgencyLocations;
	std::string AgencyName;
	std::string AgencyLocation;

	std::map<unsigned short, RentalCar*> RentalCars;
	std::map<CarBrand,unsigned short> CarPopularityList;
	std::vector<RentalTransaction> RentLogBook;
	
};


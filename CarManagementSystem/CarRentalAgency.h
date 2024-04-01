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

	unsigned short GetNumberOfCarsForRent() const;

	void ListAvaiableCarsForRent() const;

	Car* RentOutACar(const std::string);
	Car* RentOutSpecificCar(const unsigned short, const std::string);

	void CustomerReturnsACar(RentalCar*);

	unsigned int CalculateProfitFromRentedCars() const;

	void PrintMostPopularCarBrand() const;

	void PrintPopularityList() const;

	void PrintLogBook() const;

private:

	std::vector<RentalLocation*> AgencyLocations;
	void AddCarToLocation(RentalLocation* const, int&);

	std::string AgencyName;
	std::string AgencyLocation;
	
	//std::vector<RentalTransaction*> RentLogBook;
};


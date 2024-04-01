#pragma once
#include<string>
#include"RentalCar.h"
#include "RentalTransaction.h"
#include <unordered_map>
#include <map>

class RentalLocation
{
public:
	RentalLocation(const std::string, const std::string);
	~RentalLocation();

	void AddCar(const RentalCar*);

	unsigned short GetNumberOfCarsForRent() const;

	void PrintMostPopularCarBrand() const;
	void PrintPopularityList() const;

	unsigned int CalculateProfitFromRentedCars() const;

	void ListAvaiableCarsForRent() const;

	void PrintLogBook() const;

	Car* RentOutACar(const std::string);
	Car* RentOutSpecificCar(const unsigned short, const std::string);

private:
	std::string LocationName;
	std::string Location;

	std::unordered_map<unsigned short, RentalCar*> RentalCars;
	std::map<CarBrand, unsigned short> CarPopularityList;
	std::vector<RentalTransaction*> RentLogBook;
	
};


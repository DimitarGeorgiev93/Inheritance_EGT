#pragma once
#include<string>
#include"RentalCar.h"

class RentalLocation
{
public:
	RentalLocation(const std::string, const std::string);
	~RentalLocation();
private:
	std::string LocationName;
	std::string Location;

	std::map<unsigned short, RentalCar*> RentalCars;
	std::map<CarBrand, unsigned short> CarPopularityList;
	std::vector<RentalTransaction> RentLogBook;
	
};


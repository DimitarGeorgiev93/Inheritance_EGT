#pragma once
#include"CarRentalAgency.h"
#include <vector>

class Driver
{
public:
	Driver(std::string, unsigned short, bool License = false, Car* rented = nullptr);
	~Driver();

	void RentACar(CarRentalAgency* );
	void RentSpecificCar(const CarRentalAgency*, const unsigned short);
	void ReturnRentedcar();
	void PrintInfo() const;

	void DriveCar() const;
	void StopCar() const;
	

	void PutTiresOnCar();

	void BuyTires(const Tire*);
private:
	std::string DriverName;
	unsigned short DriverAge;
	bool HasDriverLicense;
	Car* RentedCar;
	Tire* StorageTires;
	CarRentalAgency* RentedACarFromHere;

	std::vector<const Car* > RentedCarHistory;


};

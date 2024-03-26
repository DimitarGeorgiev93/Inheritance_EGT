
#include <iostream>
#include "Car.h"
#include "Driver.h"
#include "CarRentalAgency.h"


int main()
{
	Car A(CarBrand::Kia, nullptr);

	Tire B(10,TireBrand::Bridgestone,TireMaterial::AramidFabric);


	Driver Pesho ("Pesho", 20);
	Driver Ivan ("Ivan", 23);

	CarRentalAgency D("2ndhandMotors","Sofia");

	D.ListAvaiableCarsForRent();
	//D.PrintMostPopularCarBrand();
	Pesho.RentSpecificCar (&D,2);
	Pesho.ReturnRentedcar();
	Ivan.RentSpecificCar (&D,2);
	Pesho.ReturnRentedcar();
	Pesho.RentSpecificCar(&D, 3);
	Pesho.ReturnRentedcar();
	Pesho.RentSpecificCar(&D, 3);
	Pesho.ReturnRentedcar();
	Pesho.RentSpecificCar(&D, 3);

	D.PrintMostPopularCarBrand();
	std::cout << std::endl;
	D.PrintPopularityList();
	//D.CalculateProfitFromRentedCars();
	D.PrintLogBook();


	return 0;
	
}


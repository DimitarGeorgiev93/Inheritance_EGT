#include "Car.h"


Car::Car(const CarBrand NewCarBrand, const Tire* NewTires) : Brand(NewCarBrand)
{
	srand(time(NULL));

	CarEngine = new Engine(rand() % 100000, rand() % 100 + 100, FuelType(rand() % 3), rand() % 500 + 500, rand() % 500 + 500);

	if (NewTires != nullptr)
	{
		Tires = NewTires;
	}
	else
	{
		Tires = nullptr;
	}
}

Car::~Car()
{
	delete CarEngine;
}

void Car::PutTiresOn(const Tire* NewTires)
{
	if (!NewTires)
	{
		std::cout << "No new tires given " << std::endl;
		return;
	}
	Tires = NewTires;
}

void Car::PrintInfo() const
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Brand: ";
	switch (Brand) {
	case 0:
		std::cout << "Opel" << std::endl;
		break;
	case 1:
		std::cout << "Kia" << std::endl;
		break;
	case 2:
		std::cout << "Mazda" << std::endl;
		break;
	}
	CarEngine->PrintEngineInfo();
	if (!Tires)
	{
		std::cout << "Not tires yet" << std::endl;
	} 
	else
	{
		Tires->PrintTireInfo();
	}

}

void Car::StartEngine() const
{
	const_cast<Engine*>(CarEngine)->StartEngine();
}

void Car::StopEngine() const
{
	const_cast<Engine*>(CarEngine)->StopEngine();
}

void Car::ChangeTires(const Tire* NewTires)
{
	
	if (!NewTires)
	{
		std::cout << "No new tires given " << std::endl;
		return;
	}
	const Tire* tempTires = Tires;
	Tires = NewTires;
	NewTires = tempTires;
}

bool Car::DoesItHaveTires() const
{
	if (Tires)
	{
		return true;
	}
	else
	{
		return false;
	}
}

CarBrand Car::GetCarBrand() const
{
	return Brand;
}

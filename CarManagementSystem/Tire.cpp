#include "Tire.h"

Tire::Tire(const unsigned short NewDiameter, const TireBrand NewBrand, const TireMaterial NewMaterial)
	: Diameter(NewDiameter), Brand (NewBrand), Material(NewMaterial)
{
	IsItRotating = false;
}

Tire::~Tire()
{
}

void Tire::RorateTire()
{
	IsItRotating = true;
}

void Tire::StopRotatingTire()
{
	IsItRotating = false;
}

const bool Tire::CheckTireStatus() const
{
	return IsItRotating;
}



void Tire::PrintTireInfo() const
{
	std::cout << "Tire Brand: ";
	switch (Brand) {
	case 0:
		std::cout << "Bridgestone" << std::endl;
		break;
	case 1:
		std::cout << "Michelin" << std::endl;
		break;
	case 2:
		std::cout << "Pirelli" << std::endl;
		break;
	case 3:
		std::cout << "Goodyear" << std::endl;
		break;
	case 4:
		std::cout << "Dunlop" << std::endl;
		break;
	}
	std::cout << "Material: ";
	switch (Material) {
	case 0:
		std::cout << "Rubber" << std::endl;
		break;
	case 1:
		std::cout << "SyntheticRubber" << std::endl;
		break;
	case 2:
		std::cout << "AramidFabric" << std::endl;
		break;
	case 3:
		std::cout << "Steel" << std::endl;
		break;
	}
	std::cout << "Diameter: " << Diameter << std::endl;
}

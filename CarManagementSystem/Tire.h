#pragma once
#include<iostream>

enum TireBrand {Bridgestone, Michelin, Pirelli, Goodyear ,Dunlop};
enum TireMaterial {Rubber, SyntheticRubber, AramidFabric, Steel};

class Tire
{
public:
	Tire(const unsigned short, const TireBrand, const TireMaterial);
	~Tire();

	void RorateTire();
	void StopRotatingTire();

	const bool CheckTireStatus() const;

	void PrintTireInfo() const;
	
private:

	bool IsItRotating;
	const unsigned short Diameter;
	const TireBrand Brand;
	const TireMaterial Material;
};


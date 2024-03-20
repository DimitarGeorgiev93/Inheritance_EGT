#pragma once
#include<string>
#include<iostream>

class Vehicle
{
public:
	Vehicle(const std::string, const std::string, const float, const float);
	virtual ~Vehicle();

	bool CanPassUnderBridge( const float) const;
	bool CanPassOverBridge(const float) const;

	//virtual void printInfo() const;

protected:
	const std::string VehicleBrand;
	const std::string VehicleModel;
	float Height;
	float Weigth;
};


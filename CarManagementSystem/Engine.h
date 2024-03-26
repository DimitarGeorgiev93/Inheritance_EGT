#pragma once
#include<iostream>

enum FuelType {Diesel, Petrol, Gas };

class Engine
{
public:
	Engine(const unsigned short,const unsigned short, const FuelType, const unsigned short, const unsigned short);
	~Engine();

	void StartEngine();
	void StopEngine();
	bool GetEngineStatus() const;

	void PrintEngineInfo() const; // print?
	

private:

	bool IsEngineOn;

	const unsigned short EngineID;
	const unsigned short HorsePower;
	const FuelType Fuel;
	const unsigned short Bulk;
	const unsigned short Weigth;
};

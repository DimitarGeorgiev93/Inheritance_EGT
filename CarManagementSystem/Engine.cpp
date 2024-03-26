#include "Engine.h"

Engine::Engine(const unsigned short NewEngineID, const unsigned short NewHorsePower, const FuelType NewFuel, const unsigned short NewBulk, const unsigned short NewWeigth)
	: EngineID(NewEngineID), HorsePower(NewHorsePower), Fuel(NewFuel), Bulk (NewBulk), Weigth(NewWeigth)
{
	IsEngineOn = false;
}

Engine::~Engine()
{
}

void Engine::StartEngine()
{
	std::cout << "Starting engine... " << std::endl;
	IsEngineOn = true;
}

void Engine::StopEngine()
{
	std::cout << "Stopping engine " << std::endl;
	IsEngineOn = false;
}

bool Engine::GetEngineStatus() const
{
	return IsEngineOn;
}

void Engine::PrintEngineInfo() const
{
	std::cout << "Engine ID: " << EngineID << std::endl;
	std::cout << "Weight: " << Weigth << std::endl;
	std::cout << "Bulk: " << Bulk << std::endl;
	std::cout << "Horse power: " << HorsePower << std::endl;
}

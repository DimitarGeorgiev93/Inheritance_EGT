#pragma once
#include "string"


struct RentalTransaction
{
	std::string ProviderAgencyName;
	std::string CustomerName;
	//std::string ProviderLocation;
	unsigned short RentalPrice;
	unsigned short VenicleID;
};


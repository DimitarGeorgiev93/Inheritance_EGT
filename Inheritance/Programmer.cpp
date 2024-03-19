#include "Programmer.h"

Programmer::Programmer(const std::string NewEmployeeName, const unsigned int NewWorkExperience, const double NewSalary, const bool NewKnowsCpp = 0)
	:Employee( NewEmployeeName, NewWorkExperience, NewSalary)
{
	KnowsCpp = NewKnowsCpp;
}

Programmer::~Programmer()
{
}

void Programmer::PrintInfo() const
{
	Employee::PrintInfo();
	if (KnowsCpp)
	{
		std::cout << " | C++: True"  << std::endl;
	}
	else 
	{
		std::cout << " | C++: False" << std::endl;
	}
}



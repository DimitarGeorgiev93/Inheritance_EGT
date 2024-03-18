#include "Programmer.h"

Programmer::Programmer(const std::string name, const unsigned workExperience, const double salary, const bool cpp = 0)
	:Employee( name, workExperience, salary)
{
	this->cpp = cpp;
}

Programmer::~Programmer()
{
	//std::cout << " deleting Name: " << Employee::GetName() << std::endl; // << std::endl;
}

void Programmer::PrintInfo() const
{
	//std::cout << "----------------------------------------" << std::endl;
	std::cout << "Name: " << Employee::GetName(); // << std::endl;
	std::cout << " | Work experience: " << Employee::GetWorkExperience(); // << std::endl;
	std::cout << " | Salary: " << Employee::GetSalary(); // << std::endl;
	if (this->cpp)
	{
		std::cout << " | C++: True"  << std::endl;
	}
	else 
	{
		std::cout << " | C++: False" << std::endl;
	}
}



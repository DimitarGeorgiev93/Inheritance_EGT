#include "Manager.h"

Manager::Manager(const std::string name, const unsigned workExperience, const double salary, const unsigned workers = 0)
	:Employee(name, workExperience,salary)
{
	this->workers = workers;
}

Manager::~Manager()
{
	//std::cout << " deleting Name: " << Employee::GetName() << std::endl; // << std::endl;
}

void Manager::PrintInfo() const
{
	//std::cout << "----------------------------------------" << std::endl;
	std::cout << "Name: " << Employee::GetName(); // << std::endl;
	std::cout << " | Work experience: " << Employee::GetWorkExperience(); // << std::endl;
	std::cout << " | Salary: " << Employee::GetSalary(); // << std::endl;
	std::cout << " | Workers: " << this->workers  << std::endl;
}

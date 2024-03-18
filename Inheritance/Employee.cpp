#include "Employee.h"

Employee::Employee(const std::string name, const unsigned workExperience, const double salary)
{
	this->name = name;
	this->workExperience = workExperience;
	this->salary = salary;
}

Employee::~Employee()
{
}

void Employee::IncreaseSalary()
{
	this->salary = this->salary + (0.01 * (this->workExperience / 12) * this->salary);
}

std::string Employee::GetName() const
{
	return this->name;
}

unsigned Employee::GetWorkExperience() const
{
	return this->workExperience;
}

double Employee::GetSalary() const
{
	return this->salary;
}

#include "Employee.h"

Employee::Employee(const std::string NewEmployeeName, const unsigned int NewWorkExperience, const double NewSalary)
{
	EmployeeName = NewEmployeeName;
	WorkExperience = NewWorkExperience;
	Salary = NewSalary;
}

Employee::~Employee()
{
}

void Employee::PrintInfo() const
{
	std::cout << "Name: " << Employee::GetName();
	std::cout << " | Work experience: " << Employee::GetWorkExperience();
	std::cout << " | Salary: " << Employee::GetSalary(); 
}

void Employee::IncreaseSalary()
{
	Salary = Salary + (0.01 * (WorkExperience / 12) * Salary);
}

std::string Employee::GetName() const
{
	return EmployeeName;
}

unsigned int Employee::GetWorkExperience() const
{
	return WorkExperience;
}

double Employee::GetSalary() const
{
	return Salary;
}

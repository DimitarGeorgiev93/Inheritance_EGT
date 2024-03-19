#pragma once

#include <string>
#include <iostream>

class Employee
{
public:
	Employee (const std::string , const unsigned int, const double);
	virtual ~Employee();

	virtual void PrintInfo() const;
	void IncreaseSalary();
	std::string GetName() const;
	unsigned GetWorkExperience() const;
	double GetSalary() const;
private:
	std::string EmployeeName;
	unsigned int WorkExperience;
	double Salary;
};


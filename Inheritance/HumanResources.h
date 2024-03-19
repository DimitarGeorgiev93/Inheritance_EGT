#pragma once
#include "Manager.h"
#include "Programmer.h"
#include <map>


class HumanResources
{
public:
	HumanResources();
	~HumanResources();

	void AddProgrammer(const std::string, const unsigned int, const double, const bool);
	void AddManager(const std::string, const unsigned int, const double, const unsigned int);
	void RemoveEmployee(const unsigned int);
	void PrintInfo() const;
	void FireALlEmployees();

	void IncreaseSalary();
	void FireInters();
private:
	std::map<unsigned int, Employee*> employeeList;

	unsigned int employeeID;
};


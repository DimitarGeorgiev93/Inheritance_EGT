#pragma once
#include "Manager.h"
#include "Programmer.h"
#include <map>


class HumanResources
{
public:
	HumanResources();
	~HumanResources();

	void AddEmployee(const std::string, const unsigned, const double, const bool);
	void AddEmployee(const std::string, const unsigned, const double, const unsigned);
	void RemoveEmployee(const unsigned);
	void PrintInfo() const;
	void deleteThemAll();

	void IncreaseSalary();
	void FireInters();
private:
	std::map<unsigned, Employee*> employeeList;

	unsigned employeeID;
};


#pragma once

#include "Employee.h"

class Programmer : public Employee
{
public:
	Programmer(const std::string, const unsigned int, const double, const bool);
	~Programmer();

	void PrintInfo() const override;

private:
	bool KnowsCpp;
};


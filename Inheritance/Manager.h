#pragma once
#include "Employee.h"

class Manager :
    public Employee
{
public:
    Manager(const std::string, const unsigned, const double, const unsigned);
    ~Manager();

    void PrintInfo() const override;
private:
    unsigned workers;
};


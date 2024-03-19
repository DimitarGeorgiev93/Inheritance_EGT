#pragma once
#include "Employee.h"

class Manager :
    public Employee
{
public:
    Manager(const std::string, const unsigned int, const double, const unsigned int);
    ~Manager();

    void PrintInfo() const override;
private:
    unsigned int WorkerCount;
};


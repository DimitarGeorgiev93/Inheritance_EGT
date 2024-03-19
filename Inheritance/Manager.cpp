#include "Manager.h"

Manager::Manager(const std::string NewEmployeeName, const unsigned int NewWorkExperience, const double NewSalary, const unsigned int NewWorkerCount = 0)
	:Employee(NewEmployeeName, NewWorkExperience, NewSalary)
{
	WorkerCount = NewWorkerCount;
}


Manager::~Manager()
{
}

void Manager::PrintInfo() const
{
	Employee::PrintInfo();
	std::cout << " | Workers: " << WorkerCount  << std::endl;
}

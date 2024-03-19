#include "HumanResources.h"

HumanResources::HumanResources()
{
	employeeID = 0;
}

HumanResources::~HumanResources()
{
	std::map<unsigned int, Employee*>::iterator itr = employeeList.begin();

	while (itr != employeeList.end())
	{
		Employee* tempEmp = itr->second;
		employeeList.erase(itr++);

		delete tempEmp;
		tempEmp = nullptr;
	}
}

void HumanResources::AddProgrammer(const std::string NewName, const unsigned int NewWorkExperience, const double NewSalary, const bool NewKnowsCpp)
{
	Employee* newProgrmammer = new Programmer(NewName, NewWorkExperience, NewSalary, NewKnowsCpp);
	employeeList.emplace( ++employeeID, newProgrmammer);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Hired " << newProgrmammer->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	newProgrmammer = nullptr;
}

void HumanResources::AddManager(const std::string NewName, const unsigned int NewWorkExperience, const double NewSalary, const unsigned int NewWorkerCount)
{
	Employee* newManager = new Manager(NewName, NewWorkExperience, NewSalary, NewWorkerCount);
	employeeList.emplace( ++employeeID, newManager);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Hired " << newManager->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	newManager = nullptr;
}

void HumanResources::RemoveEmployee(const unsigned int key)
{

	if (employeeList.find(key) == employeeList.end())
	{
		std::cout << "Invalid employee ID " << key << std::endl;
		return;
	}
	Employee* tempEmp = employeeList.at(key);
	employeeList.erase(key);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Fired " << tempEmp->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	delete tempEmp;
	tempEmp = nullptr;
	
}

void HumanResources::PrintInfo() const
{

	if (!employeeList.empty())
	{
		for (const auto& tempEmp : employeeList)
		{
			std::cout << "----------------------------------------" << std::endl;
			std::cout << "Employee ID: " << tempEmp.first << " ";
			tempEmp.second->PrintInfo();
		}
		std::cout << "----------------------------------------" << std::endl;
	}
	else
	{
		std::cout << "----------------------------------------" << std::endl;
		std::cout << "No employees currently" << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}
}

void HumanResources::FireALlEmployees()
{
	std::map<unsigned int, Employee*>::iterator itr = employeeList.begin();

	while (itr != employeeList.end())
	{
		Employee* tempEmp = itr->second;
		employeeList.erase(itr++);

		delete tempEmp;
		tempEmp = nullptr;
	}
}

void HumanResources::IncreaseSalary()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Increasing salary on long term workders ( 1% per 12 months )" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (auto& tempEmp : employeeList)
	{
		tempEmp.second->Employee::IncreaseSalary();
	}

}

void HumanResources::FireInters()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Firing inters ( less than 3 months work experience )" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::map<unsigned int, Employee*>::iterator itr = employeeList.begin();

	while (itr != employeeList.end())
	{
		if (itr->second->GetWorkExperience() <= 3)
		{
			Employee* tempEmp = itr->second;
			employeeList.erase(itr++);

			delete tempEmp;
			tempEmp = nullptr;
		}
		else
		{
			itr++;
		}
	}
}

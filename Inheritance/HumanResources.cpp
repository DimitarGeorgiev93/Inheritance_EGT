#include "HumanResources.h"

HumanResources::HumanResources()
{
	this->employeeID = 0;
}

HumanResources::~HumanResources()
{
	std::map<unsigned, Employee*>::iterator itr = this->employeeList.begin();

	while (itr != this->employeeList.end())
	{
		Employee* tempEmp = itr->second;
		this->employeeList.erase(itr++);

		delete tempEmp;
		tempEmp = nullptr;
	}
}

void HumanResources::AddEmployee(const std::string name, const unsigned workExperience, const double salary, const bool cpp)
{
	Employee* newProgrmammer = new Programmer(name, workExperience, salary, cpp);
	this->employeeList.emplace( ++employeeID, newProgrmammer);
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Hired " << newProgrmammer->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	newProgrmammer = nullptr;
}

void HumanResources::AddEmployee(const std::string name, const unsigned workExperience, const double salary, const unsigned workers)
{
	Employee* newManager = new Manager(name, workExperience, salary, workers);
	this->employeeList.emplace( ++employeeID, newManager);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Hired " << newManager->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	//this->employeeList.insert({ employeeID++, &newManager });
	newManager = nullptr;
}

void HumanResources::RemoveEmployee(const unsigned key)
{
	Employee* tempEmp = this->employeeList.at(key);
	this->employeeList.erase(key);

	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Fired " << tempEmp->GetName() << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	delete tempEmp;
	tempEmp = nullptr;
}

void HumanResources::PrintInfo() const
{

	if (!this->employeeList.empty())
	{
		for (const auto& tempEmp : this->employeeList)
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

void HumanResources::deleteThemAll()
{
	std::map<unsigned, Employee*>::iterator itr = this->employeeList.begin();

	while (itr != this->employeeList.end())
	{
		Employee* tempEmp = itr->second;
		this->employeeList.erase(itr++);

		delete tempEmp;
		tempEmp = nullptr;
	}
}

void HumanResources::IncreaseSalary()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Increasing salary on long term workders ( 1% per 12 months )" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	for (auto& tempEmp : this->employeeList)
	{
		//std::cout << "----------------------------------------" << std::endl;
		tempEmp.second->Employee::IncreaseSalary();
		//std::cout << "Employee ID: " << tempEmp.first << " ";
		//tempEmp.second->PrintInfo();
	}
	//std::cout << "----------------------------------------" << std::endl;
}

void HumanResources::FireInters()
{
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Firing inters ( less than 3 months work experience )" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	std::map<unsigned, Employee*>::iterator itr = this->employeeList.begin();

	while (itr != this->employeeList.end())
	{
		//std::cout << "-------------------asdasd---------------------" << std::endl;
		if (itr->second->GetWorkExperience() <= 3)
		{
			//std::cout << "-------------------asdasdasdasd---------------------" << std::endl;
			Employee* tempEmp = itr->second;
			this->employeeList.erase(itr++);

			delete tempEmp;
			tempEmp = nullptr;
		}
		else
		{
			itr++;
		}
	}
}

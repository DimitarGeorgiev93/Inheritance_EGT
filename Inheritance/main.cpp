

#include <iostream>
//#include "Programmer.h"
#include "HumanResources.h"

int main()
{

    HumanResources HR;
    HR.AddEmployee("Ivan", 43, 300., true);
    HR.AddEmployee("Tosho", 13, 400., true);
    HR.AddEmployee("Misho", 3, 3100., (unsigned)3);
    HR.AddEmployee("Miro", 3, 310., false);
    HR.AddEmployee("Pesho", 24, 600., false);
    HR.AddEmployee("Joro", 3, 3100., (unsigned)5);
    HR.AddEmployee("Pesho", 24, 600., false);

    HR.PrintInfo();

    HR.RemoveEmployee(3);

    HR.PrintInfo();

    HR.FireInters();

    HR.PrintInfo();

    HR.IncreaseSalary();
    //HR.deleteThemAll();

    HR.PrintInfo();

    return 0;
}


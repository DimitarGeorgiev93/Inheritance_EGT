

#include <iostream>
//#include "Programmer.h"
#include "HumanResources.h"

int main()
{

    HumanResources HR;
    HR.AddProgrammer("Ivan", 43, 300., true);
    HR.AddProgrammer("Tosho", 13, 400., true);
    HR.AddManager("Misho", 3, 3100., (unsigned int)3);
    HR.AddProgrammer("Miro", 3, 310., false);
    HR.AddProgrammer("Pesho", 24, 600., false);
    HR.AddManager("Joro", 3, 3100., (unsigned int)5);
    HR.AddProgrammer("Pesho", 24, 600., false);

    HR.PrintInfo();

    HR.RemoveEmployee(3);

    HR.RemoveEmployee(23);

    HR.PrintInfo();

    HR.FireInters();

    HR.PrintInfo();

    HR.IncreaseSalary();
    //HR.deleteThemAll();

    HR.PrintInfo();

    return 0;
}


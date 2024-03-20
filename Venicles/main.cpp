

#include <iostream>
#include "AmphibiousVehicle.h"

int main()
{
    AmphibiousVehicle A("Opel", "Corsa", 4,2000, 20, 42,5,2);
    std::cout << A.CanTheVehiclePassTheDistanceUnderAnHour(20,8,2,10);
}

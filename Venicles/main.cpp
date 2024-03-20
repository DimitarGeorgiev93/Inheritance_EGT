

#include <iostream>
#include "AmphibiousVehicle.h"
#include<ios> //used to get stream size
#include<limits> 

int main()
{
    AmphibiousVehicle A("Opel", "Corsa", 4,2000, 20, 42,5,2);
    //std::cout << A.CanTheVehiclePassTheDistanceUnderAnHour(20,8,2,10);
    A.CanPassOverBridge(5);
  
    float RoadLenght = 0, BridgeHeight = 0, WaterRoadLenght = 0, StreamSpeed = 0;
    std::cout << "Enter 4 digits: road lenght, bridge height, water road lenght, stream speed: " << std::endl;
    while (true)
    {
        while (std::cin >> RoadLenght >> BridgeHeight >> WaterRoadLenght >> StreamSpeed)
        {
            std::cout << A.CanTheVehiclePassTheDistanceUnderAnHour(RoadLenght, BridgeHeight, WaterRoadLenght, StreamSpeed) << std::endl;
            std::cout << "Enter 4 digits: road lenght, bridge height, water road lenght, stream speed:" << std::endl;
            std::cin.ignore(10000, '\n');
 /*           std::cout << "a: " << a << std::endl;
            std::cout << "b: " << b << std::endl;
            std::cout << "c: " << c << std::endl;
            std::cout << "d: " << d << std::endl;*/
        }
        if (std::cin.eof())
        {
            break;
        }
        //if (!std::cin.good() && !std::cin.eof())
        if (!std::cin.good() )
        {
            std::cout << "Invalid input, try again" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');

            //std::cin.ignore();
        }
        std::cout << "Enter 4 digits: road lenght, bridge height, water road lenght, stream speed:" << std::endl;
        std::cin.clear();
        //std::cin.ignore();
    }

    return 0;
}

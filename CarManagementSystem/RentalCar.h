#pragma once
#include "Car.h"
class RentalCar :
    public Car
{
public:
    RentalCar(const CarBrand, unsigned short, const std::string, unsigned short, const Tire* NewTires = nullptr);
    ~RentalCar();

    bool GetRentStatus() const;
    void ChangeRentPerMonth( const unsigned short);

    void PrintInfo() const override;

    unsigned short GetID() const;

    std::string GetRentalLocation() const;
    
    void ChangeRentedStatus();

    unsigned short GetRentPrice() const;

private:
    bool IsItRented;
    const unsigned short ID;
    const std::string RentalLocation;
    unsigned short RentPerMonth;
};


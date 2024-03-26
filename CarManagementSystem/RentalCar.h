#pragma once
#include "Car.h"
class RentalCar :
    public Car
{
public:
    RentalCar(const CarBrand, unsigned short, unsigned short, const Tire* NewTires = nullptr);
    ~RentalCar();

    bool GetRentStatus() const;
    void ChangeRentPerMonth( const unsigned short);

    void PrintInfo() const override;

    unsigned short GetID() const;
    
    void ChangeRentedStatus();

    unsigned short GetRentPrice() const;

private:
    bool IsItRented;
    const unsigned short ID;
    unsigned short RentPerMonth;
};


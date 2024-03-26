#pragma once
#include "Engine.h"
#include "Tire.h"
#include <vector>
#include <stdlib.h>    
#include <time.h>  
#include<iostream>

enum CarBrand {Opel, Kia, Mazda};

class Car
{
public:
	Car(const CarBrand, const Tire*);
	virtual ~Car();
	void PutTiresOn(const Tire*);
	virtual void PrintInfo() const;

	void StartEngine() const;
	void StopEngine() const;
	void ChangeTires(const Tire*);

	bool DoesItHaveTires() const;
	CarBrand GetCarBrand() const;

private:
	const Engine* CarEngine;

	const CarBrand Brand;
	//std::vector<Tire*> Tire;

	const Tire* Tires;
};


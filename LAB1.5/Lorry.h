#pragma once
#include "Car.h"

using namespace std;

class Lorry
{
private:
	Car car;
	double capacity = 0.0;
public:
	Car GetCar() const;
	double GetCapacity() const;
	bool SetCar(Car value);
	bool SetCapacity(double value);

	bool Init(string brand, int cylinders, double power, double capacity);
	void Read();
	void Display() const;
	string toString() const;

	bool ReassignBrand(string newBrand);
	bool ChangeCapacity(double newCapacity);
};


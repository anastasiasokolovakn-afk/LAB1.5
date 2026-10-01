#pragma once
#include <string>

using namespace std;
class Car
{
private:
	string brand = "";
	int cylinders = 0;
	double power = 0.0;
public:
	string GetBrand() const;
	int GetCylinders() const;
	double GetPower() const;

	bool SetBrand(string value);
	bool SetCylinders(int value);
	bool SetPower(double value);

	bool Init(string brand, int cylinders, double power);
	void Display() const;
	void Read();
	string toString() const;

	bool ChangePower(double newPower);
	bool ReassignBrand(string newBrand);
};


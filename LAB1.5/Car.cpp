#include "Car.h"
#include <iostream>
#include <sstream>
#include <string>

string Car::GetBrand() const {
	return brand;
}
int Car::GetCylinders() const {
	return cylinders;
}
double Car::GetPower() const {
	return power;
}

bool Car::SetBrand(string value) {
	if (!value.empty()) {
		brand = value;
		return true;
	}
	else {
		cout << "Не вказано бренд" << endl;
		return false;
	}
}
bool Car::SetCylinders(int value) {
	if (value > 0) {
		cylinders = value;
		return true;
	}
	else {
		return false;
	}
}
bool Car::SetPower(double value) {
	if (value > 0) {
		power = value;
		return true;
	}
	else {
		return false;
	}
}

bool Car::Init(string brand, int cylinders, double power) {
	return SetBrand(brand) && SetCylinders(cylinders) && SetPower(power);
}
void Car::Display() const {
	cout << "Машина = " << toString() << endl;
}
void Car::Read() {
	string newBrand;
	int newCylinders;
	double newPower;
	do {
		cout << "Введіть марку машини:             " << endl;
		cin >> newBrand;
		cout << "Введіть цількість цилідрів машини:" << endl;
		cin >> newCylinders;
		cout << "Введіть потужність машини:        " << endl;
		cin >> newPower;
	} while (!Init(newBrand, newCylinders, newPower));
}
string Car::toString() const {
	stringstream sout;
	sout << "(Марка: " << brand << ", Циліндри: " << cylinders << ", Потужність: " << power << ")";
	return sout.str();
}

bool Car::ChangePower(double newPower) {
	return SetPower(newPower);
}
bool Car::ReassignBrand(string newBrand) {
	return SetBrand(newBrand);
}
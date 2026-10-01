#include "Lorry.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Car Lorry::GetCar() const {
	return car;
}
double  Lorry::GetCapacity() const {
	return capacity;
}
bool  Lorry::SetCar(Car value) {
	car = value; 
	return true;
}
bool  Lorry::SetCapacity(double value) {
	if (value > 0) {
		capacity = value;
		return true;
	}
	else {
		cout << "Помилкове значення" << endl;
		return false;
	}
}

bool Lorry::Init(string brand, int cylinders, double power, double capacity) {
	Car tempCar;
	if (tempCar.Init(brand, cylinders, power) && SetCapacity(capacity)) {
		car = tempCar;
		return true;
	}
	return false;
}
void  Lorry::Read() {
	cout << "Введіть дані машини:" << endl;
	car.Read();

	double newCapacity;
	do {
		cout << "Введіть вантажопідйомність (тонн): ";
		cin >> newCapacity;
	} while (!SetCapacity(newCapacity));
}
void  Lorry::Display() const {
	cout << toString() << endl;
}
string  Lorry::toString() const {
	stringstream sout;
	sout << "Вантажівка: " << car.toString() << ", Вантажопідйомність: " << capacity << " т";
	return sout.str();
}

bool  Lorry::ReassignBrand(string newBrand) {
	return car.SetBrand(newBrand);
}
bool  Lorry::ChangeCapacity(double newCapacity) {
	return SetCapacity(newCapacity);
}
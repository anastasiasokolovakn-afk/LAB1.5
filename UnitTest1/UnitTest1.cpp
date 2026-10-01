#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB1.5/Car.h"
#include "../LAB1.5/Car.cpp"
#include "../LAB1.5/Lorry.h"
#include "../LAB1.5/Lorry.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LabUnitTests
{
    TEST_CLASS(CarTests)
    {
    public:
        TEST_METHOD(TestCarInitValid)
        {
            Car car;
            bool result = car.Init("Toyota", 4, 150.0);
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("Toyota"), car.GetBrand());
            Assert::AreEqual(4, car.GetCylinders());
            Assert::AreEqual(150.0, car.GetPower());
        }

        TEST_METHOD(TestCarInitInvalidCylinders)
        {
            Car car;
            bool result = car.Init("Toyota", -2, 150.0);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestCarReassignBrand)
        {
            Car car;
            car.Init("Ford", 6, 200.0);
            Assert::IsTrue(car.ReassignBrand("Ford Mustang"));
            Assert::AreEqual(std::string("Ford Mustang"), car.GetBrand());
            Assert::IsFalse(car.ReassignBrand(""));
        }

        TEST_METHOD(TestCarChangePower)
        {
            Car car;
            car.Init("Honda", 4, 140.0);
            Assert::IsTrue(car.ChangePower(160.0));
            Assert::AreEqual(160.0, car.GetPower());
            Assert::IsFalse(car.ChangePower(-10.0));
        }
    };

    TEST_CLASS(LorryTests)
    {
    public:
        TEST_METHOD(TestLorryInitValid)
        {
            Lorry lorry;
            bool result = lorry.Init("MAN", 6, 400.0, 18.5);
            Assert::IsTrue(result);
            Assert::AreEqual(std::string("MAN"), lorry.GetCar().GetBrand());
            Assert::AreEqual(18.5, lorry.GetCapacity());
        }

        TEST_METHOD(TestLorryInvalidCapacity)
        {
            Lorry lorry;
            bool result = lorry.Init("MAN", 6, 400.0, -5.0);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestLorrySpecialMethods)
        {
            Lorry lorry;
            lorry.Init("DAF", 6, 420.0, 20.0);

          
            Assert::IsTrue(lorry.ChangeCapacity(22.5));
            Assert::AreEqual(22.5, lorry.GetCapacity());
            Assert::IsFalse(lorry.ChangeCapacity(0.0));

            
            Assert::IsTrue(lorry.ReassignBrand("DAF XF"));
            Assert::AreEqual(std::string("DAF XF"), lorry.GetCar().GetBrand());
        }
    };
}
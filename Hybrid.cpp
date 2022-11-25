#include <iostream>
using namespace std;

class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;

    // Vehicle()
    // {
    //     cout << "Vehicle's default constructor" << endl;
    // }

    void print()
    {
        cout << "Vehicle" << endl;
    }

    Vehicle(int z)
    {
        cout << "Vehicle's Parametrized constructor " << z << endl;
        maxSpeed = z;
    }

    ~Vehicle()
    {
        cout << "Vehicle's Destructor" << endl;
    }
};

class Car : virtual public Vehicle
{
public:
    int numGears;

    Car() : Vehicle(3)
    {
        cout << "Car's default constructor" << endl;
    }

    ~Car()
    {
        cout << "Car's Destructor" << endl;
    }

    void print()
    {
        cout << "NumTyres : " << numTyres << endl;
        cout << "Color : " << color << endl;
        cout << "Num gears : " << numGears << endl;
    }
};

class Truck : virtual public Vehicle
{
public:
    Truck() : Vehicle(4)
    {
        cout << "Truck's constructor" << endl;
    }
};

class Bus : public Car, public Truck
{
public:
    Bus() : Vehicle(5)
    {
        cout << "Bus's constructor" << endl;
    }
};

int main()
{
    Bus b;
    /*
    Output without using virtual class

        Vehicle's default constructor
        Car's default constructor
        Vehicle's default constructor
        Truck's constructor
        Bus's constructor
        Vehicle's Destructor
        Car's Destructor
        Vehicle's Destructor

    */

    /*
    After using virtual class

        Vehicle's default constructor
        Car's default constructor
        Truck's constructor
        Bus's constructor
        Car's Destructor
        Vehicle's Destructor
    */

    /*
    When calling parametrized constructor Bus will make a call to
    Vehicle and not it's immediate children hence 5 is printed
    Vehicle's Parametrized constructor 5
    */
}
#include <iostream>
using namespace std;

class Vehicle
{
public:
    string color;

    virtual void print()
    {
        cout << "Vehicle" << endl;
    }
};

class Car : public Vehicle
{
public:
    int numGears;

    /*
    void print()
    {
        cout << "Car" << endl;
    }*/
};

int main()
{
    Vehicle v;

    Car c;

    v.print();

    c.print();

    // object that points to an object
    Vehicle *v1 = new Vehicle;

    // just a pointer that points to garbage
    Vehicle *v2;
    // v2 = &v;

    // also allowed
    // base class can point to object of derived class
    // but vice versa is not allowed
    v2 = &c;

    // will use print function of vehicle
    // through this pointer only those properties
    // that have been inherited from vehicle can be accessed

    // at run time it will be checked which object does v2 point to
    // implictly print of vehicle should be used but since we have made that
    // function virtual hence print of Car will be called
    v2->print();

    /*
        Output without using virtual function
        Vehicle
        Car
        Vehicle
    */

    /*
        Output using virtual function
        Vehicle
        Car
        Car

    */

    /*
         When print function of Car is commented out
         Vehicle
         Vehicle
         Vehicle
    */
}
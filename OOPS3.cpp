#include <iostream>
using namespace std;

// parent class or base class
class Vehicle
{
private:
    int maxSpeed;

protected:
    int numTyres;

public:
    string color;
    Vehicle()
    {
        cout << "Vehicle's default constructor" << endl;
    }
    Vehicle(int z)
    {
        cout << "Vehicle's Parametrized Constructor"
             << endl;
        maxSpeed = z;
    }
    ~Vehicle()
    {
        cout << "Vehicle's Destructor" << endl;
    }
};

// base class or derived class
// public inheritance
// private not inherited in any of the inheritances
// public inherited as public
// protected inherited as protected
class Car : public Vehicle
{
public:
    int numGears;
    // to call parametrized constructor of parent class
    Car()
    {
        cout << "Car's default constructor" << endl;
    }
    Car(int x) : Vehicle(x)
    // Car()
    {
        cout << "Car's parametrized constructor" << endl;
    }
    ~Car()
    {
        cout << "Car's Destructor" << endl;
    }
    void print()
    {
        numTyres = 5;
        cout << "numTyres : " << numTyres << endl;
        cout << "color : " << color << endl;
        cout << "numGears : " << numGears << endl;
        // cout<<"Max Speed : "<<maxSpeed<<endl;
    }
};

class HondaCity : public Car
{
public:
    HondaCity()
    {
        cout << "Honda City Constructor" << endl;
    }
    HondaCity(int y) : Car(y)
    {
        cout << "Honda City Parametrized Constructor" << endl;
    }
    ~HondaCity()
    {
        cout << "Honda City Destructor" << endl;
    }
};

// protected inheritance
// public and protected inherited as protected

// private inheritance
// public and protected inherited  as private
// if no access specifier is defined then by default it's taken as private

class Student
{
public:
    string name;

    void print()
    {
        cout << "Student " << endl;
    }
};

class Teacher
{
public:
    string name;
    string age;

    void print()
    {
        cout << "Teacher" << endl;
    }
};

class TA : public Teacher, public Student
{

public:
    void print()
    {
        cout << "TA " << endl;
    }
};

int main()
{
    HondaCity h;
    HondaCity h1(8);
    // Vehicle v(7);
    // v.color = "Blue";
    // // v.maxSpeed = 100;
    // // v.numTyres = 4;

    // Car c(7);
    // c.color = "Black";
    // // c.numTyres = 4;
    // c.numGears = 5;
    // cout << endl;
    // c.print();
    // cout << endl;

    TA a;

    //	a.Student :: print();

    a.print();

    a.Teacher ::name = "abcd";
}
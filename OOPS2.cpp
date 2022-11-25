#include <iostream>
#include <cstring>
using namespace std;

class Student
{
    int age;
    int rollNumber;

    // all students should not have total_students
    // it is a property of the class that should remain constant for all
    // objects. Such properties are declared static. A copy of static is not
    // created for the objects, it is just present with the class
    static int total_students;

public:
    // static functions also is for class and not a property of an object
    // as these functions aren't associated with objects static functions don't
    // have access to this keyword
    static int getTotalStudents()
    {
        return total_students;
    }
    char *name;
    // const int rollNumber;
    // int &x; //reference variable of age

    // to initialize constant variables that cannot be
    // initialized inside constructor or anywhere else we make use
    // of self inialisation list
    // we can initialize other variables too with the help of initialization list
    // initialization list also used for reference data members

    // if there exist a const or reference variable it is mandatory to implement a constructor

    // Student(int r, int age) : rollNumber(r), age(age), &x(this -> age)
    // {
    //     //rollNumber = r;
    // }
    Student()
    {
        total_students++;
    }

    Student(int age, char *name)
    {
        this->age = age;

        // creates shallow copy
        //  this->name = name;

        // Deep copy
        // creating different memory space and copying contents everytime
        // an object is created
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        total_students++;
    }

    // if we use Student s here again a shallow copy will occur to store the
    // contents of objects of main to the local object s, and since we have made an
    // explicit copy constructor the default copy constructor is not visible now so this
    // will call itself and create an infinite loop
    // in order to avoid that we pass a reference and make it constant
    Student(Student const &s)
    {
        this->age = s.age;
        // shallow copy that the inbuilt constructor makes
        //  this -> name = s.name;

        // deep copy
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void display()
    {
        cout << "Name : " << name << " Age : " << age << endl;
    }
};

// initialization of static data members
int Student ::total_students = 0;

int main()
{
    char name[] = "Tanya";
    Student s1(20, name);

    // as we made an array and passed the same array to both
    // the name of both the pointers point to the same location
    // hence they get affected whenever any changes are made to the name pointer in main

    // if make changes in name of any one object they get reflected in name
    // and hence in both of the name of both of the objects

    // this is called shallow copy

    s1.display();
    name[0] = 'M';
    Student s2(19, name);
    s2.display();
    s1.display();

    cout << endl
         << endl;

    // output for shallow copy
    /*Name : Tanya Age : 20
    Name : Manya Age : 19
    Name : Manya Age : 20*/

    // output for deep copy
    /*Name : Tanya Age : 20
    Name : Manya Age : 19
    Name : Tanya Age : 20*/

    // copy constructor

    Student s3(s1);
    s3.name[0] = 'V';
    s1.display();
    s3.display();

    // output
    /*Name : Vanya Age : 20
    Name : Vanya Age : 20*/

    // why both have Vanya? cause s3's name has also copied the pointer of
    // s1 where s1's object stores it's name, hence any changes to name of
    // s3 reflected back to s1

    // accessing static data members
    // cout << "Total students : " << Student ::total_students << endl;

    // if we change using any object then it will be reflected for all objects
    // s1.total_students = 20;
    // cout << s2.total_students << endl;
    cout << "Total students : " << Student ::getTotalStudents()
         << endl;
}
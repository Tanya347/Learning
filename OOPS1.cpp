#include <iostream>
using namespace std;

class Student
{

public:
    int rollNumber;

private:
    int age;

public:
    ~Student()
    {
        cout << "Destructor called ! " << endl;
    }

    // Default constructor
    Student()
    {
        cout << "Constreuctor called ! " << endl;
    }

    // Parameterized constructor
    Student(int rollNumber)
    {
        cout << "Constructor 2 called !" << endl;

        this->rollNumber = rollNumber;
    }

    Student(int a, int r)
    {
        cout << "this : " << this << endl;
        cout << "Constructor 3 called ! " << endl;
        this->age = a;
        this->rollNumber = r;
    }

    void display()
    {
        cout << age << " " << rollNumber << endl;
    }

    // getter
    int getAge()
    {
        return age;
    }

    // setter
    void setAge(int a, int password)
    {
        if (password != 123)
        {
            return;
        }
        if (a < 0)
        {
            return;
        }
        age = a;
    }
};

int main()
{

    // statically creating objects
    Student s1(10, 1001);
    Student s2(20, 2001);

    // dynamically creating objects
    Student *s3 = new Student(30, 3001);

    // ways to use copy assignment operator
    // can be used only for already existing objects
    s2 = s1;

    *s3 = s1;

    s2 = *s3;

    Student s4 = s2;

    delete s3;

    // copy assignment operator
    Student s1(10, 1001);
    cout << "S1 : ";
    s1.display();

    Student s2(s1);
    cout << "S2 : ";
    s2.display();

    Student s7(s1);

    Student *s3 = new Student(20, 2001);
    cout << "S3 : ";
    s3->display();

    Student s4(*s3);

    Student *s5 = new Student(*s3);
    Student *s6 = new Student(s1);
}

#include <iostream>
using namespace std;

class Fraction
{
private:
    int num;
    int den;
    void simplify();

public:
    Fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    void print() const
    {
        cout << num << "/" << den << endl;
    }

    Fraction add(Fraction const &);
    Fraction operator+(Fraction const &) const;
    Fraction operator-(Fraction const &) const;

    Fraction multiply(Fraction const &);
    Fraction operator*(Fraction const &) const;
    Fraction operator/(Fraction const &) const;

    bool operator==(Fraction const &) const;

    Fraction &operator++();
    Fraction operator++(int);

    Fraction &operator+=(Fraction const &);

    // mark after writing function name as constant
    int getNumerator() const
    {
        return num;
    }

    int getDenominator() const
    {
        return den;
    }

    void setNumerator(int n)
    {
        num = n;
    }

    void setDenominator(int d)
    {
        den = d;
    }
};

// copy contructor is being called and value of main's f2 is being copied
// into the locally created object f2 of the function
// void Fraction ::add(Fraction f2)

// hence we pass a reference no new memory is created f2 will point to the original memory itself
// but to avoid any unwanted changes to f2 we make it constant
Fraction Fraction ::add(Fraction const &f2)
{
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int n = x * num + (y * f2.num);
    // num = n;
    // den = lcm;

    Fraction f(n, lcm);
    f.simplify();

    return f;
    // we don't need to call an object here as it will implicitly take
    // the object that this points i.e f1
    // simplify();
}

// f3 = f1 + f2
// the properties of f1 will go to this
Fraction Fraction ::operator+(Fraction const &f2) const
{
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int n = x * num + (y * f2.num);

    Fraction f(n, lcm);
    f.simplify();

    return f;
}

Fraction Fraction ::operator-(Fraction const &f2) const
{
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int n = x * num - (y * f2.num);

    Fraction f(n, lcm);
    f.simplify();

    return f;
}

void Fraction ::simplify()
{
    int gcd = 1;
    int j = min(num, den);
    for (int i = 1; i <= j; i++)
    {
        if (num % i == 0 && den % i == 0)
            gcd = i;
    }
    num = num / gcd;
    den = den / gcd;
}

Fraction Fraction ::multiply(Fraction const &f2)
{
    Fraction f(num * f2.num, den * f2.den);
    f.simplify();
    return f;
}

Fraction Fraction ::operator*(Fraction const &f2) const
{
    Fraction f(num * f2.num, den * f2.den);
    f.simplify();
    return f;
}

Fraction Fraction ::operator/(Fraction const &f2) const
{
    Fraction f(num * f2.den, den * f2.num);
    f.simplify();
    return f;
}

bool Fraction::operator==(Fraction const &f2) const
{
    return (num == f2.num && den == f2.den);
}

// as this is a pointer dereference and then return
// pre-increment

// int fun(int i) {
//     i++;
//     return i;
// }
// main() {
//     cout<<fun(5);
// }
// system creates a temporary memory and recieves 6 in that
// temporary memory and prints it

// now in ++(++f1) the function is being called on the temporary memory
// but changes did not get reflected in f1 as we are trying to print f1 but the
// function was called on the temporary memory and final ans is present somewhere else
// hence when we do f3 = ++(++f1)
// we are recieving the value that came after updating the temporary block of memory
// hence we need to return by reference instead by value

// return type if by reference hence it will not making a temporary memory
// and buffer memory will point to the object itself
Fraction &Fraction::operator++()
{
    num = num + den;
    simplify();
    return *this;
}

// post increment
// In this we need to copy the old value in the variable but after doing
// that we need to increment the old value
// by putting int in argument list it is specified that this is postincrement
// nesting is not allowed in post increment operator
Fraction Fraction::operator++(int)
{
    Fraction f(num, den);
    num = num + den;
    simplify();
    f.simplify();
    return f;
}

Fraction &Fraction::operator+=(Fraction const &f2)
{
    int lcm = den * f2.den;
    int x = lcm / den;
    int y = lcm / f2.den;
    int num = x * num + (y * f2.num);

    int n = x * num + (y * f2.num);

    num = n;
    den = lcm;
    simplify();

    return *this;
}

int main()
{
    char ch;
    do
    {
        cout << "\nPERFORM OPERATIONS ON FRACTIONS :";
        cout << "\n1. Addition";
        cout << "\n2. Subtraction";
        cout << "\n3. Multiplication";
        cout << "\n4. Check Equal";
        cout << "\n5. Pre increment";
        cout << "\n6. Post increment";
        cout << "\n7. += operation";
        cout << "\n8. Division";
        cout << endl;

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;
        int data;
        switch (option)
        {
        case 1:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);
            Fraction f3 = f1 + f2;
            cout << "\nAnswer is :";
            f3.print();
            break;
        }
        case 2:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);
            Fraction f3 = f1 - f2;
            cout << "\nAnswer is :";
            f3.print();
            break;
        }
        case 3:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);
            Fraction f3 = f1 * f2;
            cout << "\nAnswer is :";
            f3.print();
            break;
        }
        case 4:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);

            if (f1 == f2)
                cout << "\nFractions are equal";
            else
                cout << "\nFractions are not equal";

            break;
        }
        case 5:
        {
            int a, b;
            cout << "\nEnter the numerator and denominator of fraction : ";
            cin >> a >> b;
            int i;
            cout << "\nWould you like to increment once or twice (enter 1 or 2) : ";
            cin >> i;
            Fraction f(a, b);
            if (i == 1)
            {
                Fraction fi = ++f;
                cout << "\nAnswer is :";
                fi.print();
            }
            else if (i == 2)
            {
                Fraction fii = ++(++f);
                cout << "\nAnswer is :";
                fii.print();
            }
            else
            {
                cout << "\nInvalid!!!\n";
            }
            break;
        }
        case 6:
        {
            int a, b;
            cout << "\nEnter the numerator and denominator of fraction : ";
            cin >> a >> b;
            Fraction f(a, b);
            Fraction fi = f++;
            cout << "\nValue stored before incrementing :";
            fi.print();
            cout << "\nValue stored in original fraction :";
            f.print();
            break;
        }
        case 7:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);
            f1 += f2;
            cout << "\nthe first fraction now is :";
            f1.print();
        }
        case 8:
        {
            int a, b, c, d;
            cout << "\nEnter numerator and denominator of fraction 1 : ";
            cin >> a >> b;
            cout << "\nEnter numerator and denominator of fraction 2 : ";
            cin >> c >> d;

            Fraction f1(a, b);
            Fraction f2(c, d);
            Fraction f3 = f1 / f2;
            cout << "\nAnswer is :";
            f3.print();
            break;
        }
        }

        cout << "\nWant to perform any more operations on the tree? (y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    // // add functions
    // Fraction fa = f1.add(f2);
    // fa.print();
    // Fraction fb = f1 + f2;
    // fb.print();
    // cout << endl
    //      << endl;

    // // multiply functions
    // Fraction fc = f2.multiply(f1);
    // fc.print();
    // Fraction fd = fa * fb;
    // fd.print();
    // cout << endl
    //      << endl;

    // // you can call only constant functions for constant objects
    // Fraction const f3(15, 19);
    // cout << f3.getNumerator() << "/" << f3.getDenominator() << endl;
    // cout << endl
    //      << endl;
    // // what are constant functions ?
    // // they don't change any property of current object

    // // increment operators
    // Fraction fe = ++f2;
    // fe.print();
    // f2.print();
    // cout << endl
    //      << endl;

    // // nested increment
    // ++(++fe);
    // fe.print();
    // cout << endl
    //      << endl;
    // // for preincrement Fraction f2 = ++f1;
    // // f1 should get updated and then its content should be pasted in f2
    // // for postincrement

    // Fraction ff = fa++;
    // ff.print();
    // fa.print();
    // cout << endl
    //      << endl;
}

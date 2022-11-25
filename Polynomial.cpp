#include <iostream>
using namespace std;

class Polynomial
{
    int capacity;

public:
    int *degCoeff;
    Polynomial()
    {
        degCoeff = new int[5];
        for (int i = 0; i < 5; i++)
        {
            degCoeff[i] = 0;
        }

        capacity = 5;
    }

    Polynomial(Polynomial const &P)
    {
        degCoeff = new int[P.capacity];
        for (int i = 0; i < P.capacity; i++)
        {
            degCoeff[i] = P.degCoeff[i];
        }
        capacity = P.capacity;
    }

    int getCoefficient(int deg)
    {
        if (deg >= capacity)
            return 0;
        else
            return degCoeff[deg];
    }

    void operator=(Polynomial const &);

    void setCoefficient(int, int);

    Polynomial operator+(Polynomial const &);
    Polynomial operator-(Polynomial const &);
    Polynomial operator*(Polynomial const &);

    void print();
};

// copy assignment operator with deep copy
void Polynomial::operator=(Polynomial const &P)
{
    delete[] degCoeff;
    degCoeff = new int[P.capacity];
    for (int i = 0; i < P.capacity; i++)
    {
        degCoeff[i] = P.degCoeff[i];
    }
    capacity = P.capacity;
}

// function to setCoefficient
void Polynomial::setCoefficient(int d, int coeff)
{
    if (d >= capacity)
    {
        int *newDegCoeff = new int[2 * capacity];
        for (int i = 0; i < 2 * capacity; i++)
        {
            newDegCoeff[i] = 0;
        }

        for (int i = 0; i < capacity; i++)
        {
            newDegCoeff[i] = degCoeff[i];
        }
        delete[] degCoeff;
        degCoeff = newDegCoeff;
        capacity = 2 * capacity;
    }
    degCoeff[d] = coeff;
}

// function to print polynomial
void Polynomial::print()
{
    for (int i = 0; i < capacity; i++)
    {
        if (degCoeff[i] != 0)
            cout << degCoeff[i] << "x" << i << " ";
    }
    cout << endl;
}

// function to perform addition of two polynomials
// Polynomial Polynomial::operator+(Polynomial const &p2)
// {
//     Polynomial pNew;
//     int minCapacity, minDegCoeff = 0;
//     if (capacity < p2.capacity)
//     {
//         minCapacity = capacity;
//         minDegCoeff = 1;
//     }
//     else if (capacity > p2.capacity)
//     {
//         minCapacity = p2.capacity;
//         minDegCoeff = 2;
//     }
//     for (int i = 0; i < capacity; i++)
//     {
//         pNew.setCoefficient(i, degCoeff[i] + p2.degCoeff[i]);
//     }

//     if (minDegCoeff == 1)
//     {
//         for (int i = minCapacity; i < p2.capacity; i++)
//         {
//             pNew.setCoefficient(i, p2.degCoeff[i]);
//         }
//     }
//     else if (minDegCoeff == 2)
//     {
//         for (int i = minCapacity; i < capacity; i++)
//         {
//             pNew.setCoefficient(i, degCoeff[i]);
//         }
//     }

//     return pNew;
// }

Polynomial Polynomial::operator+(Polynomial const &p2)
{
    Polynomial p;
    int i = 0, j = 0;
    while (i < capacity && j < p.capacity)
    {
        int deg = i;
        int coeff = degCoeff[i] + p2.degCoeff[j];
        p.setCoefficient(deg, coeff);
        i++;
        j++;
    }
    while (i < capacity)
    {
        p.setCoefficient(i, degCoeff[i]);
    }
    while (j < p2.capacity)
    {
        p.setCoefficient(j, p2.degCoeff[j]);
    }
    return p;
}

// function to perform subtraction of two polynomials
// Polynomial Polynomial::operator-(Polynomial const &p2)
// {
//     Polynomial pNew;
//     int minCapacity, minDegCoeff = 0;
//     if (capacity < p2.capacity)
//     {
//         minCapacity = capacity;
//         minDegCoeff = 1;
//     }
//     else if (capacity > p2.capacity)
//     {
//         minCapacity = p2.capacity;
//         minDegCoeff = 2;
//     }
//     for (int i = 0; i < capacity; i++)
//     {
//         pNew.setCoefficient(i, degCoeff[i] - p2.degCoeff[i]);
//     }

//     if (minDegCoeff == 1)
//     {
//         for (int i = minCapacity; i < p2.capacity; i++)
//         {
//             pNew.setCoefficient(i, -p2.degCoeff[i]);
//         }
//     }
//     else if (minDegCoeff == 2)
//     {
//         for (int i = minCapacity; i < capacity; i++)
//         {
//             pNew.setCoefficient(i, degCoeff[i]);
//         }
//     }

//     return pNew;
// }

Polynomial Polynomial::operator-(Polynomial const &p2)
{
    Polynomial p;
    int i = 0, j = 0;
    while (i < capacity && j < p.capacity)
    {
        int deg = i;
        int coeff = degCoeff[i] - p2.degCoeff[j];
        p.setCoefficient(deg, coeff);
        i++;
        j++;
    }
    while (i < capacity)
    {
        p.setCoefficient(i, degCoeff[i]);
    }
    while (j < p2.capacity)
    {
        p.setCoefficient(j, -p2.degCoeff[j]);
    }
    return p;
}

// function to perform multiplication of two polynomials
Polynomial Polynomial::operator*(Polynomial const &p2)
{
    Polynomial p;
    for (int i = 0; i < capacity; i++)
    {
        for (int j = 0; j < p2.capacity; j++)
        {
            if (degCoeff[i] != 0)
            {
                int deg = i + j;
                int coeff = p.getCoefficient(deg) + (degCoeff[i] * p2.degCoeff[j]);
                p.setCoefficient(deg, coeff);
            }
        }
    }
    return p;
}

int main()
{
    int count1, count2, choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for (int i = 0; i < count1; i++)
    {
        cin >> degree1[i];
    }

    for (int i = 0; i < count1; i++)
    {
        cin >> coeff1[i];
    }

    Polynomial first;
    for (int i = 0; i < count1; i++)
    {
        first.setCoefficient(degree1[i], coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for (int i = 0; i < count2; i++)
    {
        cin >> degree2[i];
    }

    for (int i = 0; i < count2; i++)
    {
        cin >> coeff2[i];
    }

    Polynomial second;
    for (int i = 0; i < count2; i++)
    {
        second.setCoefficient(degree2[i], coeff2[i]);
    }

    first.print();
    second.print();

    cin >> choice;

    Polynomial result;
    switch (choice)
    {
        // Add
    case 1:
        result = first + second;
        result.print();
        break;
        // Subtract
    case 2:
        result = first - second;
        result.print();
        break;
        // Multiply
    case 3:
        result = first * second;
        result.print();
        break;

    case 4: // Copy constructor
    {
        Polynomial third(first);
        if (third.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }

    case 5: // Copy assignment operator
    {
        Polynomial fourth(first);
        if (fourth.degCoeff == first.degCoeff)
        {
            cout << "false" << endl;
        }
        else
        {
            cout << "true" << endl;
        }
        break;
    }
    }

    return 0;
}

/*
5
0 1 2 3 5
4 3 -3 4 5
5
0 1 2 3 5
2 5 7 8 3
*/
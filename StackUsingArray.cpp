#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class stack
{
private:
    T *arr;
    int nextIndex;
    int capacity;

public:
    stack()
    {
        capacity = 5;
        arr = new T[5];
        nextIndex = 0;
    }
    ~stack()
    {
    }
    void push(T);
    void pop();
    T top();
    int size();
    bool empty();
};

template <typename T>
void stack<T>::push(T element)
{
    if (nextIndex == capacity)
    {
        int *newArr = new T[2 * capacity];
        for (int i = 0; i < capacity; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = 2 * capacity;
    }
    arr[nextIndex] = element;
    nextIndex++;
}

template <typename T>
void stack<T>::pop()
{
    if (nextIndex == 0)
    {
        cout << "\nStack is empty" << endl;
        return;
    }
    nextIndex--;
}

template <typename T>
T stack<T>::top()
{
    if (nextIndex <= 0)
    {
        cout << "\nStack is empty";
        return 0;
    }

    return arr[nextIndex - 1];
}

template <typename T>
int stack<T>::size()
{
    return nextIndex;
}

template <typename T>
bool stack<T>::empty()
{
    return (nextIndex == 0);
}

int main()
{
    stack<int> s;
    int i = 1;
    cout << "Enter elements of stack, enter -1 to terminate : " << endl;
    cout << "Enter element "
         << i
         << " : ";

    int data;
    cin >> data;
    while (data != -1)
    {
        s.push(data);
        i++;
        cout << "Enter element "
             << i
             << " : ";
        cin >> data;
    }
    char ch;
    cout << "\nWant to perform any operations on the linked list? (y/n) : ";
    cin >> ch;

    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nPERFORM OPERATIONS ON STACK :";

        cout << "\n1. Insert element to stack";
        cout << "\n2. Delete top of stack";
        cout << "\n3. Get top of stack";
        cout << "\n4. Get size of stack";
        cout << "\n5. Check is stack empty";

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "\nEnter element "
                 << " : ";

            cin >> data;
            s.push(data);
            cout << "\nTop of stack now is : " << s.top();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "\nTop of stack initially is : " << s.top();
            cout << endl;
            s.pop();
            if (!s.empty())
                cout << "\nTop of stack after popping is : " << s.top();
            else
                cout << "\nStack is now empty";
            cout << endl;
            break;
        }
        case 3:
        {
            if (!s.empty())
                cout << "\nTop of stack is : " << s.top();
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "\nSize of stack is : " << s.size();
            cout << endl;
            break;
        }
        case 5:
        {
            if (s.empty())
                cout << "\nStack is empty" << endl;
            else
                cout << "\nStack is not empty" << endl;
            break;
        }
        default:
            cout << "\nInvalid option!!!\n";
        }

        cout << "\nWant to perform any more operations on the stack? (y/n) : ";
        cin >> ch;
    }

    cout << "\nGood Bye :(\n"
         << endl;
}

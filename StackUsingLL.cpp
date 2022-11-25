#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class stack
{
private:
    Node<T> *head;
    int stackSize;

public:
    stack()
    {
        head = NULL;
        stackSize = 0;
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
    Node<T> *newNode = new Node<T>(element);
    newNode->next = head;
    head = newNode;
    stackSize++;
}

template <typename T>
void stack<T>::pop()
{
    if (stackSize == 0)
    {
        cout << "\nCannot delete from empty stack";
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    stackSize--;
}

template <typename T>
T stack<T>::top()
{
    if (stackSize == 0)
    {
        cout << "\nStack is empty";
        return 0;
    }

    return head->data;
}

template <typename T>
int stack<T>::size()
{
    return stackSize;
}

template <typename T>
bool stack<T>::empty()
{
    return (stackSize == 0);
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
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
class queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int qSize;

public:
    queue()
    {
        head = NULL;
        tail = NULL;
        qSize = 0;
    }
    ~queue()
    {
    }
    void push(T);
    void pop();
    T front();
    int size();
    bool empty();
};

template <typename T>
void queue<T>::push(T element)
{
    Node<T> *newNode = new Node<T>(element);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
    qSize++;
}

template <typename T>
void queue<T>::pop()
{
    if (empty())
    {
        cout << "\nQueue is empty" << endl;
        return;
    }
    Node<T> *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
    size--;
}

template <typename T>
T queue<T>::front()
{
    if (empty())
    {
        cout << "\nQueue is empty" << endl;
        return 0;
    }

    return head->data;
}

template <typename T>
int queue<T>::size()
{
    return qSize;
}

template <typename T>
bool queue<T>::empty()
{
    return (qSize == 0);
}

int main()
{
    queue<int> q;
    int i = 1;
    cout << "Enter elements of queue, enter -1 to terminate : " << endl;
    cout << "Enter element "
         << i
         << " : ";

    int data;
    cin >> data;
    while (data != -1)
    {
        q.push(data);
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
        cout << "\nPERFORM OPERATIONS ON queue :";

        cout << "\n1. Insert element to queue";
        cout << "\n2. Delete front of queue";
        cout << "\n3. Get front of queue";
        cout << "\n4. Get size of queue";
        cout << "\n5. Check is queue empty";

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
            q.push(data);
            cout << "\nFront of queue now is : " << q.front();
            cout << endl;
            break;
        }
        case 2:
        {
            cout << "\nFront of queue initially is : " << q.front();
            cout << endl;
            q.pop();
            if (!q.empty())
                cout << "\nFront of queue after popping is : " << q.front();

            cout << endl;
            break;
        }
        case 3:
        {
            if (!q.empty())
                cout << "\nFront of queue is : " << q.front();
            cout << endl;
            break;
        }
        case 4:
        {
            cout << "\nSize of queue is : " << q.size();
            cout << endl;
            break;
        }
        case 5:
        {
            if (q.empty())
                cout << "\nqueue is empty" << endl;
            else
                cout << "\nqueue is not empty" << endl;
            break;
        }
        default:
            cout << "\nInvalid option!!!\n";
        }

        cout << "\nWant to perform any more operations on the queue? (y/n) : ";
        cin >> ch;
    }

    cout << "\nGood Bye :(\n"
         << endl;
}

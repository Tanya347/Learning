#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class queue
{
private:
    T *arr;
    int nextIndex;
    int firstIndex;
    int capacity;
    int qSize;

public:
    queue()
    {
        capacity = 5;
        arr = new T[5];
        nextIndex = 0;
        firstIndex = -1;
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
    if (qSize == capacity)
    {
        T *newArr = new T[2 * capacity];
        int j = 0;
        for (int i = firstIndex; i < capacity; i++)
        {
            newArr[j++] = arr[i];
        }
        for (int i = 0; i < firstIndex; i++)
        {
            newArr[j++] = arr[i];
        }
        delete[] arr;
        arr = newArr;

        firstIndex = 0;
        nextIndex = capacity;
        capacity = 2 * capacity;
    }

    arr[nextIndex] = element;
    nextIndex = (nextIndex + 1) % capacity;
    qSize++;
    if (firstIndex == -1)
        firstIndex = 0;
}

template <typename T>
void queue<T>::pop()
{
    if (empty())
    {
        cout << "\nQueue is empty" << endl;
        return;
    }
    firstIndex = (firstIndex + 1) % capacity;
    qSize--;
    if (qSize == 0)
    {
        firstIndex = -1;
        nextIndex = 0;
    }
}

template <typename T>
T queue<T>::front()
{
    if (firstIndex == -1)
    {
        cout << "\nQueue is empty" << endl;
        return 0;
    }

    return arr[firstIndex];
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

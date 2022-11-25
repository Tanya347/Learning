#include <iostream>
using namespace std;

template <typename T>
class DynamicArray
{
    T *data;
    int nextIndex;
    int capacity; // total size

public:
    DynamicArray()
    {
        data = new T[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d)
    {
        // this -> data = d.data; // shallow copy

        this->data = new T[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void add(T element)
    {
        if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = 2 * capacity;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    T get(int i) const
    {
        if (i >= capacity)
        {
            cout << "Out of Bounds" << endl;
            return 0;
        }
        return data[i];
    }

    void add(int i, T element)
    {
        if (i < nextIndex)
        {
            data[i] = element;
        }
        else if (i == nextIndex)
        {
            add(element);
        }
        else
            return;
    }

    void operator=(DynamicArray const &d)
    {
        this->data = new T[d.capacity];
        for (int i = 0; i < d.nextIndex; i++)
        {
            this->data[i] = d.data[i];
        }
        this->nextIndex = d.nextIndex;
        this->capacity = d.capacity;
    }

    void print() const
    {
        for (int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // int
    DynamicArray<int> d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);
    d1.add(40);
    d1.add(50);
    d1.add(60);

    cout << "Your array is : " << endl;
    d1.print();

    DynamicArray<int> d2(d1);
    DynamicArray<int> d3;
    d3 = d1;
    d1.add(0, 100);
    cout << "Your array after changes is : " << endl;
    d1.print();
    cout << endl;
    cout << "Your array first copied array (using deep copy constructor) is : " << endl;
    d2.print();
    cout << endl;
    cout << "Your array first copied array (using copy assignment operator) is : " << endl;
    d3.print();
    cout << endl;

    // char
    DynamicArray<char> d4;
    d4.add('p');
    d4.add('a');
    d4.add('n');
    d4.add('d');
    d4.add('a');

    d4.print();
}
#include <iostream>
#include <string>
using namespace std;

// the value that can be stored for a particular key
// can be of any type, hence we take a template

// for ease of implementation we are taking the key to be string

// the custom data type is like a linked list with two variables key and value
// and the next node
template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

// using template again as we need it for value
template <typename V>

// ourmap class that implements the basic functionalities of a map
class ourmap
{
    // array of heads of linked lists
    MapNode<V> **buckets;
    int count;
    int numBuckets;

    // function that generates a hashcode and returns its compressed version
    int getBucketIndex(string key)
    {
        int hashCode = 0, currentCoeff = 1;

        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets;
        }

        return hashCode % numBuckets;
    }

    void rehash()
    { // create a new array and traverse the entire old array node by node
        // and insert into the new array
        MapNode<V> **temp = buckets;
        int oldBucketCount = numBuckets;
        numBuckets *= 2;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
        int count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    // searching a value
    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    // inserting into the map
    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        // travel the length of the linked list to see if the key
        // exists, if it does then update the value and return
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // if the key does not exist then make a new node and insert it
        // at the beginning of the linkedlist
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        // rehashing when the load factor exceeds 0.7
        double loadFactor = (1.0 * count) / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    // function to remove a key value pair
    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        // prev to store the previous node so we can easily delete the required node
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                // means we have to delete head
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }

                // store the value and free the node
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }

            prev = head;
            head = head->next;
        }

        return 0;
    }

    // returns current number of elements in the hashmap
    int getSize()
    {
        return count;
    }

    // destructor that first recursively deletes the linked lists
    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }

        delete[] buckets;
    }
};

int main()
{
    ourmap<int> map;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        map.insert(key, value);
        cout << map.getLoadFactor() << endl;
    }
    cout << map.getSize() << endl;
    map.remove("abc2");
    map.remove("abc7");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << map.getValue(key) << endl;
    }

    cout << map.getSize() << endl;
}

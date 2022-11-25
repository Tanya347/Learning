#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

Node *takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *temp = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            temp = n;
        }
        else
        {
            temp->next = n;
            temp = temp->next;
        }
        cin >> data;
    }
    return head;
}

/******************************** FUNCTIONS TO PERFORM OPERATIONS ON LL **********************************/

// insert node at ith position iteratively
Node *insertNode(Node *head, int i, int data)
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = temp;
        head = newNode;
        return head;
    }

    while (count < i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else
    {
        cout << "Index out of bounds" << endl;
    }

    return head;
}

// insert node at ith position recursively
Node *insertNodeRec(Node *head, int i, int data)
{
    if (head == NULL)
        return head;

    if (i == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }

    head->next = insertNodeRec(head->next, i - 1, data);
    return head;
}

// Delete node at ith position iteratively
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if (head == NULL)
        return head;

    Node *temp = head;

    if (pos == 0)
    {
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    int count = 0;

    while (count < pos - 1 && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return head;
    }

    if (temp != NULL)
    {
        Node *a = temp->next;
        temp->next = a->next;
        a->next = NULL;
        delete a;
    }

    return head;
}

// delete node at ith position recursively
Node *deleteNodeRec(Node *head, int pos)
{
    if (head == NULL)
        return head;

    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }

    head->next = deleteNodeRec(head->next, pos - 1);
}

// find length iteratively
int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

// find length recursively
int lengthRec(Node *head)
{
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}

// print what is present at ith position
void printIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    while (i != count && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp != NULL)
        cout << temp->data;

    else
        cout << "Index out of bounds";
}

// find node iteratively
int findNode(Node *head, int n)
{
    if (head == NULL)
        return -1;

    Node *temp = head;
    int index = -1;

    while (temp != NULL)
    {
        if (temp->data == n)
        {
            index++;
            break;
        }
        else
        {
            index++;
            temp = temp->next;
        }
    }

    return index;
}

// find node recursively
int findNodeRec(Node *head, int n)
{
    if (head == NULL)
        return -1;

    if (head->data == n)
        return 0;

    int pos = findNodeRec(head->next, n);

    return (pos == -1) ? -1 : 1 + pos;
}

// return mid node
Node *midPoint(Node *head)
{
    if (head == NULL)
        return head;

    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main()
{
    cout << "\nInsert linked list (end with -1) : " << endl;
    Node *head = takeInput();
    cout << "\nYour linked list is : " << endl;
    print(head);
    cout << endl;

    char ch;
    cout << "\nWant to perform any operations on the linked list? (y/n) : ";
    cin >> ch;

    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nPERFORM OPERATIONS ON LINKED LIST :";
        cout << "\n1. Length of LL";
        cout << "\n2. Delete at ith index";
        cout << "\n3. Insert at ith index";
        cout << "\n4. Print node at ith index";
        cout << "\n5. Find node";
        cout << "\n6. Middle Node";

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "\nLength of LL using iteration : " << length(head);
            cout << "\nLength of LL using recursion : " << lengthRec(head) << endl;
            break;
        }
        case 2:
        {
            int index, a;
            cout << "\nEnter the index of the node you want to delete : ";
            cin >> index;
            cout << "\nWant to delete iteratively(1) or recursively(2) : ";
            cin >> a;
            if (a == 1)
            {
                head = deleteNode(head, index);
            }
            else if (a == 2)
            {
                head = deleteNodeRec(head, index);
            }
            cout << "\nYour linked list is : " << endl;
            print(head);
            cout << endl;
            break;
        }
        case 3:
        {
            int index, a, d;
            cout << "\nEnter the index where you want to insert : ";
            cin >> index;
            cout << "\nEnter the data you want to insert : ";
            cin >> d;
            cout << "\nWant to insert iteratively(1) or recursively(2) : ";
            cin >> a;
            if (a == 1)
            {
                head = insertNode(head, index, d);
            }
            else if (a == 2)
            {
                head = insertNodeRec(head, index, d);
            }
            cout << "\nYour linked list is : " << endl;
            print(head);
            cout << endl;
            break;
        }
        case 4:
        {
            int index;
            cout << "Enter the index of the node you want to see : ";
            cin >> index;
            cout << "\nData is : ";
            printIthNode(head, index);
            cout << endl;
            break;
        }
        case 5:
        {
            int d;
            cout << "\nEnter the data you want to search : ";
            cin >> d;
            cout << "\nIndex is (Iterative) : " << findNode(head, d);
            cout << "\nIndex is (Recursive) : " << findNodeRec(head, d);
            cout << endl;
            break;
        }
        case 6:
        {
            Node *mid = midPoint(head);
            cout << "\nMiddle node is : " << mid->data << endl;
            break;
        }
        default:
            cout << "\nInvalid option!!!\n";
        }

        cout << "\nWant to perform any more operations on the linked list? (y/n) : ";
        cin >> ch;
    }

    cout << "\nGood Bye :(\n"
         << endl;
}
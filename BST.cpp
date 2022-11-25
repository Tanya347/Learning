#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

class BST
{
    // Define the data members

    BinaryTreeNode<int> *root;

    // Helper function to print
    void printTree(BinaryTreeNode<int> *root)
    {

        if (root == NULL)
        {
            return;
        }

        cout << root->data << ":";
        if (root->left != NULL)
        {
            cout << "L:" << root->left->data << ",";
        }

        if (root->right != NULL)
        {
            cout << "R:" << root->right->data;
        }
        cout << endl;
        printTree(root->left);
        printTree(root->right);
    }

    // Helper function to insert into BST
    BinaryTreeNode<int> *insertData(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
        {
            BinaryTreeNode<int> *tree = new BinaryTreeNode<int>(data);
            return tree;
        }

        if (data > root->data)
        {
            root->right = insertData(root->right, data);
        }

        else if (data <= root->data)
        {
            root->left = insertData(root->left, data);
        }

        return root;
    }

    // Helper function to delete a node from the tree
    BinaryTreeNode<int> *deleteData(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return NULL;

        // if node to be deleted found
        if (root->data == data)
        {

            // case 1 when it is leaf node simply delete and return null
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // case 2 where one child is not null simply delete the root and return
            // not null child
            else if (root->left != NULL && root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }

            else if (root->left == NULL && root->right != NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }

            // both of them are not null then choose the min most from the right subtree replace it with
            // the root and return the root, and delete the child we copied
            else if (root->left != NULL && root->right != NULL)
            {

                BinaryTreeNode<int> *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deleteData(temp, temp->data);
                return root;
            }

            // my approach for this function
            //             else if(root -> left != NULL && root -> right != NULL) {

            //                 BinaryTreeNode<int>* temp = root;
            //                 BinaryTreeNode<int>* prev = NULL;
            //                 while(temp -> left != NULL && temp -> right != NULL) {
            //                     prev = temp;
            //                     temp = temp -> right;
            //                 }
            //                 root -> data = temp -> data;
            //                 delete temp;
            //                 prev -> right = NULL;
            //                 return root;
            //             }
        }

        // check the left and right subtree accordingly if not found
        else if (root->data < data)
        {
            root->right = deleteData(root->right, data);
        }

        else
        {
            root->left = deleteData(root->left, data);
        }

        return root;
    }

    // Helper function just recieves a tree, recieves a data and searches
    bool hasData(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;

        else if (data < root->data)
        {
            return hasData(root->left, data);
        }

        else
        {
            return hasData(root->right, data);
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    /*----------------- Public Functions of BST -----------------*/

    void remove(int data)
    {
        // Implement the remove() function
        root = deleteData(root, data);
    }

    void print()
    {
        // Implement the print() function
        printTree(root);
    }

    void insert(int data)
    {
        // Implement the insert() function
        root = insertData(root, data);
    }

    bool search(int data)
    {
        // Implement the search() function
        return hasData(root, data);
    }

    ~BST()
    {
        delete root;
    }
};

int main()
{
    BST *tree = new BST();
    char ch;

    do
    {
        cout << "\nPERFORM OPERATIONS ON TREE :";
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Search";
        cout << "\n4. Print";
        cout << endl;

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;
        int data;
        switch (option)
        {
        case 1:
        {
            cout << "\nEnter the data you want to insert : ";
            cin >> data;
            tree->insert(data);
            break;
        }
        case 2:
        {
            cout << "\nEnter the data you want to delete : ";
            cin >> data;
            tree->remove(data);
            break;
        }
        case 3:
        {
            cout << "\nEnter the data you want to search : ";
            cin >> data;
            bool ans = tree->search(data);
            if (ans)
                cout << "\nData is present";
            else
                cout << "\nData is not present";
            break;
        }
        case 4:
        {
            cout << endl;
            tree->print();
            cout << endl;
        }
        }

        cout << "\nWant to perform any more operations on the tree? (y/n) : ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}
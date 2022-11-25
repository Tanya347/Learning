#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;
    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

/********** FUNCTIONS TO TAKE INPUT, DELETE AND PRINT ***********/

// Take input level wise
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> nodes;

    nodes.push(root);

    while (!nodes.empty())
    {
        TreeNode<int> *parent = nodes.front();
        nodes.pop();
        cout << "Enter number of children of " << parent->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter child " << i << endl;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            parent->children.push_back(child);
            nodes.push(child);
        }
    }

    return root;
}

// Take tree input recursively
TreeNode<int> *takeInputRecursive()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInputRecursive();
        root->children.push_back(child);
    }

    return root;
}

// Use bfs concept to print the tree level wise
void printLevelWise(TreeNode<int> *root)
{
    // Write your code here

    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        TreeNode<int> *parent = nodes.front();
        nodes.pop();
        cout << parent->data << ":";

        for (int i = 0; i < parent->children.size(); i++)
        {
            TreeNode<int> *child = parent->children[i];
            if (i != parent->children.size() - 1)
                cout << child->data << ",";
            else
                cout << child->data;
            nodes.push(child);
        }

        cout << endl;
    }
}

// Uses dfs concept to print the tree
void printTreeRecursive(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        if (i != root->children.size() - 1)
            cout << root->children[i]->data << ",";
        else
            cout << root->children[i]->data;
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeRecursive(root->children[i]);
    }
}

// either use this function or make use of destructor
void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }
    delete root;
}

/********** FUNCTIONS THAT TELL ABOUT THE TREE ***********/

// Function to count the no. of nodes present in a tree
int countNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return 1 + count;
}

// Function to find the sum of all nodes in the tree
int sumOfNodes(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int sum = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sumOfNodes(root->children[i]);
    }
    return sum + root->data;
}

// Function to find the node with max data in the entire tree
TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;

    TreeNode<int> *max = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *curr_max = maxDataNode(root->children[i]);
        if (curr_max->data > max->data)
            max = curr_max;
    }

    return max;
}

// Function to return the height of the tree
int getHeight(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int height = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int curr_height = getHeight(root->children[i]);
        height = max(height, curr_height);
    }

    return 1 + height;
}

// Function to print all nodes present on a level k
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

// Function to find the number of leaf nodes present in a tree
int getLeafNodeCount(TreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    if (root->children.size() == 0)
        return 1;

    int count = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }

    return count;
}

/********** TRAVERSALS ***********/

// parent first and then child
void preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

// child first and then parent
void postorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }

    cout << root->data << " ";
}

/********** MAIN FUNCTION ***********/

int main()
{
    cout << "\nEnter 1 if you want to take input and print recursively" << endl;
    cout << "\nEnter 2 if you want to take input and print level wise" << endl;
    int choice;
    cin >> choice;

    TreeNode<int> *root;
    if (choice == 1)
    {
        root = takeInputRecursive();
        cout << "\nYour Tree is : " << endl
             << endl;
        printTreeRecursive(root);
    }
    else
    {
        root = takeInputLevelWise();
        cout << "\nYour Tree is : " << endl
             << endl;
        printLevelWise(root);
    }

    char ch;
    cout << "\nWant to perform any operations on the tree? (y/n) : ";
    cin >> ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "\nPERFORM OPERATIONS ON TREE :";
        cout << "\n1. Number of Nodes :";
        cout << "\n2. Sum of All Nodes";
        cout << "\n3. Max node value";
        cout << "\n4. Height of Tree";
        cout << "\n5. Nodes at a Level";
        cout << "\n6. Number of Leaf nodes";
        cout << "\n7. Traversals";

        int option;
        cout << "\n\nEnter the operation you want to peform : ";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            cout << "\nThe number of nodes present in the Tree is " << countNodes(root) << endl;
            break;
        }
        case 2:
        {
            cout << "\nThe sum of all nodes present in the Tree is " << sumOfNodes(root) << endl;
            break;
        }
        case 3:
        {
            cout << "\nThe max node value is " << maxDataNode(root)->data << endl;
            break;
        }
        case 4:
        {
            cout << "\nThe height of the tree is " << getHeight(root) << endl;
            break;
        }
        case 5:
        {
            cout << "\nEnter the level whose nodes you want to view : ";
            int k;
            cin >> k;
            printAtLevelK(root, k);
            cout << endl;
            break;
        }
        case 6:
        {
            cout << "\nThe number of leaf nodes present in the tree is " << getLeafNodeCount(root) << endl;
            break;
        }
        case 7:
        {
            cout << "\n\nTRAVERSAL MENU";
            cout << "\n1. Pre order Traversal";
            cout << "\n2. Post order Traversal";
            cout << "\nEnter you choice : ";
            int traversal_choice;
            cin >> traversal_choice;
            switch (traversal_choice)
            {
            case 1:
            {
                cout << "\nPreorder Traversal\n";
                preorder(root);
                cout << endl;
                break;
            }
            case 2:
            {
                cout << "\nPostorder Traversal\n";
                postorder(root);
                cout << endl;
                break;
            }
            default:
                cout << "Invalid option!!";
                break;
            }
            break;
        }
        default:
            cout << "\nOption not known!";
            break;
        }

        cout << "\nWant to perform any more operations on the tree? (y/n) : ";
        cin >> ch;
    }

    cout << "\nGood Bye :(\n"
         << endl;
    delete root;
}

// 6 3 4 10 9 2 3 2 1 1 3 12 7 5 0 0 2 11 8 0 0 0 0 0
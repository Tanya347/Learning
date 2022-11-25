#include <iostream>
#include <string>
using namespace std;

class TrieNode
{
public:
    char data;
    // array to store all the children of a given node
    TrieNode **children;
    // stores the fact that whether or not this particular node is a terminal or not
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
private:
    TrieNode *root;

    // HELPER FUNCTION TO IMPLEMENT INSERTION
    void insertWord(TrieNode *root, string word)
    {
        // all characters have been inserted make this node the terminal
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // if the character is present as a child then simply call recursion on
        // next character in the word else create a new node and make it the child
        // of the root
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertWord(child, word.substr(1));
    }

    // HELPER FUNCTION TO IMPLEMENT SEARCH
    bool searchWord(TrieNode *root, string word)
    {
        // if we have traversed the whole string check if this node is a terminal or not
        // which indicates whether or not the word was inserted initially
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';

        // if the character is present move on to the next character else simply return false
        if (root->children[index] != NULL)
        {
            return searchWord(root->children[index], word.substr(1));
        }
        else
            return false;
    }

    // HELPER FUNCTION TO IMPLEMENT DELETION OF A WORD
    void removeWord(TrieNode *root, string word)
    {
        // if we have reached the last character make the isTerminal of the node false
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';

        // if child is present make a call on the next child else simply return false
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        else
        {
            // word not found
            return;
        }

        removeWord(root->children[index], word.substr(1));

        // remove child if it is useless i.e. if its isTerminal is false
        // and it has no children, free the node and disconnect it from the parent
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }

public:
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool searchWord(string word)
    {
        return searchWord(root, word);
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

int main()
{
    int choice;
    cout << "Enter choice : " << endl;
    cin >> choice;
    Trie t;

    while (choice != -1)
    {
        string word;
        bool ans;
        switch (choice)
        {
        case 1: // insert
            cout << "\nEnter the word you want to insert : " << endl;
            cin >> word;
            t.insertWord(word);
            break;
        case 2: // search
            cout << "\nEnter the word you want to search : " << endl;
            cin >> word;
            cout << "\n"
                 << (t.searchWord(word) ? "Word is present\n" : "Word is not present\n");
            break;
        case 3: // remove
            cout << "\nEnter the word you want to search : " << endl;
            cin >> word;
            t.removeWord(word);
            cout << "\nWord removed" << endl;
        default:
            return 0;
        }
        cout << "Enter choice : " << endl;
        cin >> choice;
    }

    return 0;
}
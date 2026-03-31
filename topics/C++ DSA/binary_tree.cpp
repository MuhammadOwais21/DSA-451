#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value)
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool search(Node* root, int key)
{
    if (root == NULL)
        return false;

    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void displayTree(Node* root, int space)
{
    if (root == NULL)
        return;

    space += 5;

    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    displayTree(root->left, space);
}

int main()
{
    Node* root = NULL;
    int choice, value;

    while (true)
    {
        cout << "\n1. Insert\n2. Search\n3. Display Tree\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;
            root = insert(root, value);
        }
        else if (choice == 2)
        {
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value))
                cout << "Value Found\n";
            else
                cout << "Value Not Found\n";
        }
        else if (choice == 3)
        {
            cout << "\nTree Structure:\n";
            displayTree(root, 0);
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value, bool atstart) {
    Node* newNode = new Node;
    newNode->data = value;

    
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    
    if (atstart) {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    
    else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

int search(Node* head, int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return -1;
    }

    Node* temp = head;
    do {
        if (temp->data == key) {
            cout << "The value is found: " << temp->data << "\n";
            return key;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found\n";
    return -1;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}
int main() {
    Node* head = NULL;
    int choice, value;

    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                insertAtEnd(head, value);
                cout << "Node inserted.\n";
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                search(head, value);
                break;

            case 3:
                display(head);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
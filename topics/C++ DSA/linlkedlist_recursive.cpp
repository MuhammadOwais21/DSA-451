#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printForward(Node* head) {
    if (head == NULL) return;
    cout << head->data << " ";
    printForward(head->next);
}

void printReverse(Node* head) {
    if (head == NULL) return;
    printReverse(head->next);
    cout << head->data << " ";
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Insert Node";
        cout << "\n2. Print Forward (Recursion)";
        cout << "\n3. Print Reverse (Recursion)";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertNode(value);
                break;

            case 2:
                cout << "Forward: ";
                printForward(head);
                cout << endl;
                break;

            case 3:
                cout << "Reverse: ";
                printReverse(head);
                cout << endl;
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}

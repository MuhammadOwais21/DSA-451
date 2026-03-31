#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insertAtEnd(Node* &head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}


int search(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return temp->data;   // returns int
        temp = temp->next;
    }
    return -1;
}


void deleteNode(Node* &head, int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted\n";
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current != NULL && current->data != key) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Value not found\n";
        return;
    }

    previous->next = current->next;
    delete current;
    cout << "Node deleted\n";
}

int main() {
    Node* head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Linked List: ";
    display(head);

    cout << "\nValue Search: ";
    int result = search(head, 20);

    if (result != -1)
        cout << result << " found";
    else
        cout << "Value not found";

    cout << "\n\nDeleting 30...\n";
    deleteNode(head, 30);

    cout << "Updated List: ";
    display(head);

    return 0;
}

#include <iostream>
using namespace std;

#define SIZE 7

class HashTable {
private:
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int hash = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (hash + i * i) % SIZE;

            if (table[index] == -1 || table[index] == -2) {
                table[index] = key;
                cout << "Inserted at index " << index << endl;
                return;
            }
        }

        cout << "Hash Table is Full!\n";
    }

    void search(int key) {
        int hash = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (hash + i * i) % SIZE;

            if (table[index] == key) {
                cout << "Element found at index " << index << endl;
                return;
            }

            if (table[index] == -1)
                break;
        }

        cout << "Element not found!\n";
    }

    void deleteKey(int key) {
        int hash = hashFunction(key);

        for (int i = 0; i < SIZE; i++) {
            int index = (hash + i * i) % SIZE;

            if (table[index] == key) {
                table[index] = -2;
                cout << "Element deleted from index " << index << endl;
                return;
            }

            if (table[index] == -1)
                break;
        }

        cout << "Element not found!\n";
    }

    void display() {
        cout << "\nIndex\tValue\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << "\t";
            if (table[i] == -1)
                cout << "Empty";
            else if (table[i] == -2)
                cout << "Deleted";
            else
                cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int choice, key;

    do {
        cout << "\n--- Quadratic Probing Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            h.insert(key);
            break;

        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            h.search(key);
            break;

        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            h.deleteKey(key);
            break;

        case 4:
            h.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}

#include <iostream>
#include <list>
using namespace std;

#define SIZE 7

class HashTable {
private:
    list<int> table[SIZE];

public:
    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted at index " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);

        for (int value : table[index]) {
            if (value == key) {
                cout << "Element found at index " << index << endl;
                return;
            }
        }

        cout << "Element not found!\n";
    }

    void deleteKey(int key) {
        int index = hashFunction(key);

        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (*it == key) {
                table[index].erase(it);
                cout << "Element deleted from index " << index << endl;
                return;
            }
        }

        cout << "Element not found!\n";
    }

    void display() {
        cout << "\nIndex\tValues\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << "\t";
            for (int value : table[i]) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable h;
    int choice, key;

    do {
        cout << "\n--- Open Hashing Menu ---\n";
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

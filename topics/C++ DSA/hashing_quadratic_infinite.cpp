#include <iostream>
using namespace std;

class HashTable {
    int *table;
    int size;

public:
    HashTable(int s) {
        size = s;
        table = new int[size];
        for(int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int i = 0;

        while(i < size) {
            int newIndex = (index + i*i) % size;

            if(table[newIndex] == -1) {
                table[newIndex] = key;
                cout << "Inserted at index " << newIndex << endl;
                return;
            }
            i++;
        }

        cout << "Hash Table is Full. Cannot Insert." << endl;
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << i << " --> ";
            if(table[i] != -1)
                cout << table[i];
            else
                cout << "Empty";
            cout << endl;
        }
    }
};

int main() {
    int size, choice, key;
    cout << "Enter size of hash table: ";
    cin >> size;

    HashTable ht(size);

    do {
        cout << "\n1. Insert\n2. Display\n3. Exit\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                ht.display();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice";
        }

    } while(choice != 3);

    return 0;
}

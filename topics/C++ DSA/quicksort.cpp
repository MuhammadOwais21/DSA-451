#include <iostream>
using namespace std;

int arr[10];
int n = 0;

void quickSort(int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];   
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[right];
        arr[right] = temp;

        int pi = i + 1;

        quickSort(left, pi - 1);
        quickSort(pi + 1, right);
    }
}

void display() {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n1. Insert Elements\n2. Display Array\n3. Quick Sort\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter number of elements (max 10): ";
                cin >> n;
                if (n < 1 || n > 10) {
                    cout << "Invalid size!\n";
                    n = 0;
                    break;
                }
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                break;
            }
            case 2:
                if (n == 0)
                    cout << "Array is empty!\n";
                else
                    display();
                break;
            case 3:
                if (n == 0)
                    cout << "Array is empty! Insert elements first.\n";
                else {
                    quickSort(0, n - 1);
                    cout << "Array Sorted\n";
                }
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid Choice\n";
        }

    } while (choice != 4); 

    return 0;
}

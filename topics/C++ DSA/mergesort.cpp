#include <iostream>
using namespace std;

int arr[100];
int temp[100];
int n;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
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
        cout << "\n1. Insert Elements";
        cout << "\n2. Display Array";
        cout << "\n3. Merge Sort";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter number of elements: ";
                cin >> n;
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                break;

            case 2:
                display();
                break;

            case 3:
                mergeSort(0, n - 1);
                cout << "Array Sorted\n";
                break;

            case 4:
                break;

            default:
                cout << "Invalid Choice";
        }

    } while (choice != 4);

    return 0;
}


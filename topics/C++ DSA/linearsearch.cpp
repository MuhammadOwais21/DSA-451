#include <iostream>
using namespace std;
int linearSearch(int a[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
            return i; // element found at index i
    }
    return -1; // element not found
}
int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int n = 5;
    int key = 30;

    int result = linearSearch(a, n, key);

    if(result != -1)
        cout << "Found at index " << result;
    else
        cout << "Not Found";

    return 0;
}
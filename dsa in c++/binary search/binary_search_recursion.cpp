#include <iostream>
using namespace std;

int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key);
        else
            return binarySearchRecursive(arr, low, mid - 1, key);
    }
    return -1;
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 25;

    int result = binarySearchRecursive(arr, 0, n - 1, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found!";

    return 0;
}

// Important Notes
// Array must be sorted (ascending or descending).
// Works best on large datasets.
// Does not work on unsorted arrays.
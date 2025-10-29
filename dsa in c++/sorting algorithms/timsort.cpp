#include <iostream>
#include <algorithm>
using namespace std;

const int RUN = 32; // Typical run size used in Tim Sort

// Function to perform Insertion Sort on a small array (run)
void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Function to merge two sorted subarrays
void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];

    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    // Merge the two arrays
    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy remaining elements
    while (i < len1)
        arr[k++] = left[i++];
    while (j < len2)
        arr[k++] = right[j++];
}

// Function to perform Tim Sort
void timSort(int arr[], int n) {
    // Step 1: Sort individual subarrays of size RUN using Insertion Sort
    for (int i = 0; i < n; i += RUN)
        insertionSort(arr, i, min((i + RUN - 1), (n - 1)));

    // Step 2: Start merging from size RUN (32) to bigger sizes
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {5, 21, 7, 23, 19, 12, 15, 8, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    timSort(arr, n);

    cout << "\nSorted array:\n";
    printArray(arr, n);

    return 0;
}

#include <iostream>
using namespace std;

// Function to perform Cycle Sort
void cycleSort(int arr[], int n) {
    int writes = 0; // To count the number of writes (swaps)

    // Traverse array elements and put them to the right place
    for (int cycle_start = 0; cycle_start <= n - 2; cycle_start++) {
        int item = arr[cycle_start];

        // Find where to place the item
        int pos = cycle_start;
        for (int i = cycle_start + 1; i < n; i++)
            if (arr[i] < item)
                pos++;

        // If the item is already in the correct position
        if (pos == cycle_start)
            continue;

        // Skip duplicates
        while (item == arr[pos])
            pos++;

        // Put the item to its right position
        if (pos != cycle_start) {
            swap(item, arr[pos]);
            writes++;
        }

        // Rotate the rest of the cycle
        while (pos != cycle_start) {
            pos = cycle_start;

            // Find where to put the item
            for (int i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;

            // Skip duplicates
            while (item == arr[pos])
                pos++;

            // Put the item to its right position
            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }

    cout << "\nTotal number of writes: " << writes << endl;
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main() {
    int arr[] = {20, 40, 50, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    printArray(arr, n);

    cycleSort(arr, n);

    cout << "\nSorted array:\n";
    printArray(arr, n);

    return 0;
}

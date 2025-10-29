#include <iostream>
using namespace std;

int main() {
    // 1️⃣ Declaration and Initialization
    int arr[5]; // Declare an array of size 5

    // 2️⃣ Taking Input
    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }

    // 3️⃣ Displaying Elements
    cout << "\nArray elements are: ";
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }

    // 4️⃣ Finding Maximum and Minimum
    int max = arr[0], min = arr[0];
    for (int i = 1; i < 5; i++) {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    cout << "\nMaximum element: " << max;
    cout << "\nMinimum element: " << min;

    // 5️⃣ Searching an element
    int key;
    cout << "\n\nEnter element to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Element not found!" << endl;

    return 0;
}

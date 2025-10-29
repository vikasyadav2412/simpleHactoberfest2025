#include <iostream>
using namespace std;

template <typename T>
int linearSearch(T arr[], int n, T key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    string arr[] = {"apple", "banana", "cherry", "mango"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string key = "mango";

    int result = linearSearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

#include <iostream>
#include <map>
using namespace std;

int main() {
    int arr[] = {10, 20, 10, 30, 40, 20, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    map<int, int> freq;

    // Count frequency
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    cout << "Element Frequency:\n";
    for (auto it : freq)
        cout << it.first << " -> " << it.second << endl;

    return 0;
}

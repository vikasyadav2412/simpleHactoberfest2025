#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s = {5, 1, 3, 2, 4};

    cout << "Elements in sorted order: ";
    for (auto it = s.begin(); it != s.end(); ++it)
        cout << *it << " ";

    cout << "\nSmallest element: " << *s.begin();
    cout << "\nLargest element: " << *s.rbegin();

    return 0;
}

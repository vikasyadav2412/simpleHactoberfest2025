#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // Inserting elements
    s.insert(10);
    s.insert(20);
    s.insert(10);  // duplicate ignored
    s.insert(30);

    // Displaying elements
    cout << "Set elements: ";
    for (auto it : s) {
        cout << it << " ";
    }
    cout << endl;

    // Searching element
    int key = 20;
    if (s.find(key) != s.end())
        cout << key << " found in set." << endl;
    else
        cout << key << " not found." << endl;

    // Removing an element
    s.erase(10);

    cout << "After erasing 10: ";
    for (auto it : s)
        cout << it << " ";
    cout << endl;

    return 0;
}

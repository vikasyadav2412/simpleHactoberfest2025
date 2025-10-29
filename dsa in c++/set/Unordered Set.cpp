#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {50, 10, 20, 40, 30};

    cout << "Unordered set elements: ";
    for (auto it : us)
        cout << it << " ";

    cout << endl;
    us.insert(60);
    us.erase(10);

    cout << "After modifications: ";
    for (auto it : us)
        cout << it << " ";

    return 0;
}

#include <iostream>
#include <set>
using namespace std;

int main() {
    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);
    ms.insert(20);

    cout << "Multiset elements: ";
    for (auto it : ms)
        cout << it << " ";

    ms.erase(ms.find(10)); // removes one instance of 10

    cout << "\nAfter one erase: ";
    for (auto it : ms)
        cout << it << " ";

    return 0;
}

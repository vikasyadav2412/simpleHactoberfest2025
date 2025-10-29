#include <iostream>
#include <set>
using namespace std;

int main() {
    set<string> names = {"gp", "alex", "john", "emma"};

    cout << "Names in set:\n";
    for (auto &name : names)
        cout << name << endl;

    names.insert("mike");
    names.erase("john");

    cout << "\nAfter modifications:\n";
    for (auto &name : names)
        cout << name << endl;

    return 0;
}

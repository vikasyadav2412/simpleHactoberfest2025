#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    unordered_map<string, int> mp;

    // Insertion
    mp["gp"] = 100;
    mp["john"] = 90;
    mp["emma"] = 85;

    // Traversal
    cout << "Hash Table (unordered_map):\n";
    for (auto it : mp)
        cout << it.first << " --> " << it.second << endl;

    // Searching
    string key = "gp";
    if (mp.find(key) != mp.end())
        cout << "\nFound " << key << " with value " << mp[key] << endl;
    else
        cout << "\nKey not found!\n";

    // Deletion
    mp.erase("emma");

    cout << "\nAfter deleting 'emma':\n";
    for (auto it : mp)
        cout << it.first << " --> " << it.second << endl;

    return 0;
}


// ✅ Time Complexity:

// Insert/Search/Delete → O(1) average (O(n) worst case due to collisions)
// ✅ Uses: Hash tables for keys like strings, ints, etc.
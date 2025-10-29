#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // -1 indicates empty slot
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        if (table[index] == -1)
            table[index] = key;
        else
            cout << "Collision detected at index " << index << " for key " << key << endl;
    }

    bool search(int key) {
        int index = hashFunction(key);
        return (table[index] == key);
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++)
            cout << i << " --> " << table[i] << endl;
    }
};

int main() {
    HashTable ht;
    ht.insert(5);
    ht.insert(15);
    ht.insert(25);
    ht.insert(35);

    ht.display();

    cout << "\nSearching 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    cout << "Searching 20: " << (ht.search(20) ? "Found" : "Not Found") << endl;

    return 0;
}

// ✅ Time Complexity:

// Insert/Search/Delete → O(1) average

// Worst Case → O(n) (when collision occurs

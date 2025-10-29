#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    int hashFunction(int key) {
        return key % SIZE;
    }

    void insert(int key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != -1) {
            index = (index + 1) % SIZE;
            if (index == start) {
                cout << "Hash Table is Full!\n";
                return;
            }
        }
        table[index] = key;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int start = index;
        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % SIZE;
            if (index == start)
                break;
        }
        return false;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++)
            cout << i << " --> " << table[i] << endl;
    }
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(60);
    ht.display();

    cout << "\nSearching 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;
    cout << "Searching 80: " << (ht.search(80) ? "Found" : "Not Found") << endl;
    return 0;
}


// ✅ Handles collisions using linear probing
// ✅ Open addressing technique
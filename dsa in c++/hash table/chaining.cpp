#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int BUCKET; // number of buckets
    list<int> *table; // pointer to array of lists

public:
    HashTable(int V) {
        BUCKET = V;
        table = new list<int>[BUCKET];
    }

    int hashFunction(int key) {
        return key % BUCKET;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void display() {
        for (int i = 0; i < BUCKET; i++) {
            cout << i;
            for (auto x : table[i])
                cout << " --> " << x;
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insertItem(15);
    ht.insertItem(11);
    ht.insertItem(27);
    ht.insertItem(8);
    ht.insertItem(12);

    cout << "\nInitial Hash Table:\n";
    ht.display();

    ht.deleteItem(12);
    cout << "\nAfter deleting 12:\n";
    ht.display();

    return 0;
}


// ✅ Collision Handling: Separate Chaining (Linked Lists)
// ✅ Time Complexity: O(1) average for all operations
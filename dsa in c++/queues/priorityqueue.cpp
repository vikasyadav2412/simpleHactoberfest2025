#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq; // Max-Heap by default

    pq.push(10);
    pq.push(50);
    pq.push(20);
    pq.push(5);

    cout << "Priority Queue elements (descending): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;
    return 0;
}

// A Queue works on the FIFO (First In, First Out) principle:
// 👉 The element added first is removed first.
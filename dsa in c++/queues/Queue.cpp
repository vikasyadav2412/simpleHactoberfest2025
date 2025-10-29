#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Insert elements (enqueue)
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.back() << endl;

    // Remove elements (dequeue)
    q.pop();

    cout << "\nAfter one pop:\n";
    cout << "Front element: " << q.front() << endl;

    cout << "\nQueue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}

// A Queue works on the FIFO (First In, First Out) principle:
// 👉 The element added first is removed first.
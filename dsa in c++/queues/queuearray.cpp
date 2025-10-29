#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;
    int capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[cap];
        front = 0;
        size = 0;
        rear = cap - 1;
    }

    bool isFull() { return size == capacity; }
    bool isEmpty() { return size == 0; }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " enqueued to queue\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued from queue\n";
        front = (front + 1) % capacity;
        size--;
    }

    int Front() {
        if (isEmpty()) return -1;
        return arr[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return arr[rear];
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.Front() << endl;
    q.dequeue();
    cout << "Front after dequeue: " << q.Front() << endl;

    return 0;
}


// A Queue works on the FIFO (First In, First Out) principle:
// 👉 The element added first is removed first.
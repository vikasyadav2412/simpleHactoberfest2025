#include <iostream>
using namespace std;

class MaxHeap {
    int* heapArr;
    int capacity;
    int heap_size;

public:
    MaxHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        heapArr = new int[cap];
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insertKey(int k) {
        if (heap_size == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // Insert new key at end
        heap_size++;
        int i = heap_size - 1;
        heapArr[i] = k;

        // Fix the max heap property
        while (i != 0 && heapArr[parent(i)] < heapArr[i]) {
            swap(heapArr[i], heapArr[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap_size && heapArr[l] > heapArr[largest])
            largest = l;
        if (r < heap_size && heapArr[r] > heapArr[largest])
            largest = r;

        if (largest != i) {
            swap(heapArr[i], heapArr[largest]);
            heapify(largest);
        }
    }

    int extractMax() {
        if (heap_size <= 0)
            return INT_MIN;
        if (heap_size == 1) {
            heap_size--;
            return heapArr[0];
        }

        int root = heapArr[0];
        heapArr[0] = heapArr[heap_size - 1];
        heap_size--;
        heapify(0);

        return root;
    }

    void printHeap() {
        for (int i = 0; i < heap_size; i++)
            cout << heapArr[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h(10);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "Max-Heap elements: ";
    h.printHeap();

    cout << "Extracted Max: " << h.extractMax() << endl;

    cout << "Heap after extraction: ";
    h.printHeap();
}




// min Heap implemention







#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> heap;

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    void heapifyDown(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:

    void initializeHeap() {
        heap.clear();
    }

    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void changeKey(int index, int new_val) {
        if (index < 0 || index >= heap.size()) {
            cout << "Index out of bounds\n";
            return;
        }

        int old_val = heap[index];
        heap[index] = new_val;

        if (new_val < old_val)
            heapifyUp(index);
        else
            heapifyDown(index);
    }

    void extractMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        // Replace root with last element
        heap[0] = heap.back();
        heap.pop_back();

        heapifyDown(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int getMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    int heapSize() {
        return heap.size();
    }

    // Optional: print heap for debugging
    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << "\n";
    }
};

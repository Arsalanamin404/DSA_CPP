#include <iostream>
#define MAX_SIZE 100
using namespace std;

class MaxHeap
{
private:
    int Heap[MAX_SIZE];
    int size;
    inline int parent(int i) { return (i - 1) / 2; }
    inline int left_child(int i) { return (2 * i) + 1; }
    inline int right_child(int i) { return (2 * i) + 2; }

    void heapifyUp(int i)
    {
        // repeat until we reach root and parent is less than than child
        while (i != 0 && Heap[parent(i)] < Heap[i])
        {
            swap(Heap[i], Heap[parent(i)]);
            i = parent(i);
        }
    }
    void heapifyDown(int i, int heapsize)
    {
        int largest = i;
        int left = this->left_child(i);
        int right = this->right_child(i);

        if (left < heapsize && Heap[left] > Heap[largest])
            largest = left;
        if (right < heapsize && Heap[right] > Heap[largest])
            largest = right;

        if (largest != i)
        {
            swap(Heap[i], Heap[largest]);
            heapifyDown(largest, heapsize);
        }
    }

public:
    MaxHeap() { size = 0; }

    void insert(int value)
    {
        if (size == MAX_SIZE)
        {
            cout << "============== HEAP OVERFLOW ==============" << endl;
            return;
        }
        Heap[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "============== HEAP UNDERFLOW ==============" << endl;
            return;
        }
        Heap[0] = Heap[size - 1];
        size--;
        heapifyDown(0, size);
    }

    inline int getMax()
    {
        if (size == 0)
        {
            cout << "============== HEAP UNDERFLOW ==============" << endl;
            return -1;
        }
        return Heap[0];
    }

    void heapSort()
    {
        for (int i = size - 1; i > 0; i--)
        {
            swap(Heap[0], Heap[i]);
            heapifyDown(0, i);
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
            cout << Heap[i] << " ";
        cout << endl;
    }

    bool isEmpty() { return this->size == 0; }
};

int main()
{
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(30);
    h.insert(50);
    h.insert(35);
    h.insert(45);

    h.display();
    h.heapSort();
    h.display();

    return 0;
}

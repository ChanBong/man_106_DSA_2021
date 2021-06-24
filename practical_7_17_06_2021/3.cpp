#include<bits/stdc++.h>
using namespace std;

class HEAP{
    int size;
    int* heap;

public:
    HEAP(int* A, int N);
    void heapify(int parent, int size);
    void heapification();
    void heapsort();
    void display();
};

HEAP::HEAP (int *A, int N){
    size = N, heap = A;
}

void HEAP::heapify(int parent, int last){
    int left = 2*parent + 1;
    int right = 2*parent + 2;

    int largest = 0;

    if (left <= last && heap[left] > heap[parent]) largest = left;
    else largest = parent;

    if (right <= last && heap[right] > heap[largest]) largest = right;

    if (largest != parent) {
        cout << "swapping " << heap[parent] << " and " << heap[largest] << "\n";
        this->display();
        swap(heap[parent], heap[largest]);
        heapify(largest, last);
    }
    else return;
}

void HEAP::heapification(){
    int middle = 0;

    if ((size)%2) middle = (size - 3)/2;
    else middle = (size - 2)/2;

    for (int i=middle; i>=0; i--) heapify(i, size-1);
    return ;
}

void HEAP::heapsort(){
    heapification();
    cout << "Max-heapification done\n";
    int i = size-1;
    while( i>=0){
        swap(heap[0], heap[i]);
        heapify(0, --i);
    }
}

void HEAP::display(){
    for(int i=0; i<size; i++) cout << heap[i] << " ";
    cout << "\n\n";
}


int main(){

    int A[] = {23, 72, 16, 30, 19,76, 42, 65, 25, 10, 80};

    HEAP h(A, 11);

    cout << "Heap before sorting\n";
    h.display();
    h.heapsort();
    cout << "Sorted Heap\n";
    h.display();

}

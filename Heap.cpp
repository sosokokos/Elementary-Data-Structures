//  Created by Daniel Surina on 2022-03-20.

#include <iostream>
#include <vector>

using std::cout;
using std::endl;


//Template
template <class T>
class Heap {
private:
    T* heap;
    int heapSize;
    int used;
public:
    //Constructors
    Heap(const int &size);
    Heap(const Heap &copy);
    //Destructor
    ~Heap();
    //Other Member Functions
    Heap operator = (const Heap &copy);
    void insert(const T &item);
    T remove();
    T peek() const;
    Heap merge(Heap &heap);
    int size() const;
    
    //Helper Functions
    void bubbleUp(const int &index);
    void bubbleDown(const int &index);
    //Delete after use
    void print();
};
//Constructors
template <class T>
Heap<T>::Heap(const int &size) {
    heap = new T[size];
    heapSize = size;
    used = 0;
}

template <class T>
Heap<T>::Heap(const Heap &copy) {
    heap = new T[copy.heapSize];
    heapSize = copy.heapSize;
    used = copy.used;
    
    for(int i(0); i < copy.heapSize; i++) {
        heap[i] = copy.heap[i];
    }
}

//Destructor
template <class T>
Heap<T>::~Heap() {
    delete[] heap;
    heapSize = 0;
    used = 0;
}

//Member Functions
template <class T>
Heap<T> Heap<T>::operator = (const Heap &copy) {
    if(used > 0)
        this->~Heap();
    
    heap = new T[copy.heapSize];
    heapSize = copy.heapSize;
    used = copy.used;
    
    for(int i(0); i < copy.used; i++) {
        heap[i] = copy.heap[i];
    }
    
    return *this;
}

template <class T>
void Heap<T>::insert(const T &item) {
    if(used == heapSize)
        throw  std::runtime_error("Heap FULL! there is not enough space in the heap");
    
    heap[used] = item;
    bubbleUp(used);
    used++;
}

template <class T>
T Heap<T>::remove() {
    if(used == 0)
        throw  std::runtime_error("Heap Empty! there is no element in the heap");
    
    T anws = this->peek();
    
    heap[0] = heap[this->size() - 1];
    used--;
    bubbleDown(0);
    
    return anws;
}

template <class T>
T Heap<T>::peek() const {
    if (used == 0)
        throw std::runtime_error("Heap Empty! there is no element stored in the heap");
    return heap[0];
}

template <class T>
Heap<T> Heap<T>::merge(Heap &heap) {
    Heap anws(this->size() + heap.size());
    
    for(int i(0); i < this->size(); i++) {
        anws.insert(this->heap[i]);
        bubbleDown(0);
    }
    for(int i(0); i < heap.size(); i++) {
        anws.insert(heap.heap[i]);
        bubbleDown(0);
    }
    
    return anws;
}

template <class T>
int Heap<T>::size() const {
    return used;
}

//Helper Functions
template <class T>
void Heap<T>::bubbleUp(const int &index) {
    int parent = (index - 1) / 2;
    
    if(index > 0 && heap[index] > heap[parent]) {
        T temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;
        bubbleUp(parent);
    }
}

template <class T>
void Heap<T>::bubbleDown(const int &index) {
    T lChild = 2 * index + 1;
    T rChild = 2 * index + 2;
    T largest = index;

    if (lChild <= this->size() && heap[lChild] > heap[largest])
        largest = lChild;
    
    if (rChild <= this->size() && heap[rChild] > heap[largest])
        largest = rChild;
    
    if (largest != index) {
        T temp = heap[index];
        heap[index] = heap[largest];
        heap[largest] = temp;
        bubbleDown(largest);
    }

}

template<class T>
void Heap<T>::print() {
    for(int i(0); i < used; i++) {
        cout << heap[i] << endl;
    }
}


int main() {
    
    return 0;
}



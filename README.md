# Elementary-Data-Structures

## **Overview**
This repository contains 3 files each implementing duque (double-ended-queue), heap, and a few sorting algorithms

---

## **Files**
### **DequeT.cpp**
- Implements a double-ended queue, allowing insertion and deletion from both ends.
- Supports operations such as:
- push_front(), push_back()- pop_front(), pop_back()
- front(), back()
- Checking if the deque is empty

### **Heap.cpp**
- Implements a heap data structure, also know as priority queue
- Supports operations such as:
- insert()
- delete()
- heapify()
- getMin() or getMax() (depending on the type of heap implemented)
- extractMin() or extractMax()

### **SortingAlgorithms.cpp**
-	Contains implementations of multiple sorting algorithms such as:
-	Insertion Sort
-	Quick Sort
-	Shell Sort
-	Bubble Sort

---

## **Setup**
### Dependencies
- **Libraries**:
  - `iostream` for I/O
  - `vector` for handling vecotrs in C++
- **C++ Compiler**
  - I used g++ but you are welcome to use any alternative

### Compiling the Code
Ensure you have g++ (or complier of your choice) installed along with the required libraries. Compile the source code (using g++ as an example):
```r
g++ -o deque DequeT.cpp
g++ -o heap Heap.cpp
g++ -o sorting SortingAlgorithms.cpp
```
### Running the Executable
You can run individial or all executables using:
```r
./deque
./heap
./sorting
```

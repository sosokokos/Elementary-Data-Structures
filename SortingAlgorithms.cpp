#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//Insertion Sort
template <class T>
int insertionSort(T *arr, const int &size) {
    int BarOperations = 0;
    int j;
    T val;
    
    for (int i(1); i < size; i++) {
        j = i - 1;
        val = arr[i];
        
        while (j >= 0 && val < arr[j]) {
            arr[j + 1] = arr[j];
            j = j - 1;
            BarOperations++;
        }
        BarOperations++;
        arr[j + 1] = val;
    }
    return BarOperations;
}

//Quick Sort
template <class T>
void swap(T *arr, const int &index, const int &index2) {
    T temp = arr[index];
    arr[index] = arr[index2];
    arr[index2] = temp;
}

template <class T>
int prt(T *arr, int low, int high, int &barOp) {
    T pivot = arr[low];
    int i = low;
    int j = high;
    
    while(i < j) {
        i++;
        j--;
        
        while(arr[i] <= pivot) {
            i++;
            barOp++;
        }
        while(arr[j] > pivot) {
            j--;
            barOp++;
        }
        
        if (i < j) {
            swap(arr, i, j);
        }
    }
    swap(arr, low, j);
    return j;
}

template<class T>
void qs(T *arr, const int &low, const int &high, int &barOp) {
    int j;
    if(low < high) {
        j = prt(arr, low, high, barOp);
        qs(arr, low, j, barOp);
        qs(arr, j+1, high, barOp);
    }
}

template<class T>
int quickSort(T *arr, const int &size) {
    int barOp = 0;
    qs(arr, 0, size-1, barOp);
    return barOp;
}

//Shell Sort 
//retrieved from: https://www.geeksforgeeks.org/shellsort/
template <class T>
int shellSort(T *arr, int n) {
    int barOperations = 1;
    
    for (int gap = n/2; gap > 0; gap /= 2) {
        barOperations += 2;
        
        for (int i = gap; i < n; i += 1) {
            T temp = arr[i];
 
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
                barOperations++;
            }
             
            arr[j] = temp;
            barOperations += 4;
        }
    }
    return barOperations;
}


int main() {
    
    int arr[] = {9, 6, 2, 5, 8, 3, 1, 0, 7, 6, 7, 8, 9};
    std::string sarr[5] = {"Daniel", "Anna", "Mark", "Rob", "Ted"};
    
    cout << "# of operations: " << shellSort<std::string>(sarr, 5) << endl;
    
    for(int i(0); i < 5; i++)
        cout << sarr[i] << endl;
    
    return 0;
}

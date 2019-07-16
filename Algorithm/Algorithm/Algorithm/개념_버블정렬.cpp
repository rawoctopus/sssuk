#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000

void mySwap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int *arr, int size) {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-i-1; j++) {
            if(arr[i] > arr[i+1])
                mySwap(arr[i], arr[i+1]);
        }
    }
}

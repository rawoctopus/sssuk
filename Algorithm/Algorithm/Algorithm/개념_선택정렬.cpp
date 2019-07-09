#include <stdio.h>
#include <iostream>

using namespace std;

void mySwap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void selection_sort(int *arr, int size) {
    for(int i = 0; i < size; i++) {
        int minidx = i;
        for(int j = i+1; j < size; j++) {
            if(arr[minidx] > arr[j])
                minidx = j;
        }
        mySwap(arr[i], arr[minidx]);
    }
}

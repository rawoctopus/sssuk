/****************************Quick Sort(퀵 정렬)*********************************
 [개념]
 - 하나의 리스트를 피봇을 기준으로 두 개의 비균등한 크기로 분할하고, 분할된 부분 리스트를 정렬한 다음, 두 개의
 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 방법.
 - 분할 : 입력 배열을 피봇을 기준으로 두 개의 비균등한 크기로 분할.
 - 정복 : 부분 배열 정렬. 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용하여 다시 분할 정복 적용.
 - 결합 : 정렬된 부분 배열들을 하나의 배열에 합병.
 => 순환 호출이 진행될 때마다 최소한 하나의 원소(피봇)는 최종적으로 위치가 정해지기 때문에 해당 알고리즘이
 끝난다는 것을 보장할 수 있음.
 
 핵심은 pivot을 잘 설정하여 왼쪽 파티션과 오른쪽 파티션을 잘 나누는 것이다.
 왜냐하면 pivot을 해당 구간의 중앙값으로 잘 설정하면 merge sort와 같은 시간 복잡도인
 O(nlogn)에 수행할 수 있지만, 만약 매 케이스마다 구간의 가장 큰 값이나 가장 작은 값으로 나눠버리면
 O(n^2)의 수행시간을 갖게 된다.
 ********************************************************************************/

#include <iostream>
#include <algorithm>

void quickSort(int *arr, int left, int right) {
    int pivot = arr[left];
    int left_temp = left;
    int right_temp = right;
    
    while(left < right) {
        
        while(arr[right] >= pivot && (left < right))
            right--;
        
        if(left != right)
            arr[left] = arr[right];
        
        while(arr[left] <= pivot && (left < right))
            left++;
        
        if(left != right) {
            arr[right] = arr[left];
            right--;
        }
    }
    
    arr[left] = pivot;
    pivot = left;
    left = left_temp;
    right = right_temp;
    
    if(left < pivot)
        quickSort(arr, left, pivot-1);
    if(right > left)
        quickSort(arr, pivot+1, right);
}

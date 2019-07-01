//
//  Heap.c
//  DataStructure
//
//  Created by Sukho Lim on 01/07/2019.
//  Copyright © 2019 Sukho Lim. All rights reserved.
//

//완전 이진 트리의 일종으로 우선순위 큐를 위하여 만들어진 자료구조.
//여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아내도록 만들어진 자료구조.
// 부모 노드의 키 값이 자식 노드의 키 값보다 항상 큰(작은) 이진 트리

/*****************************************************
 - 힙을 저장하는 표준적인 자료구조는 배열이다.
 - 구현을 쉽게 하기 위하여 배열의 첫 번째 인덱스인 0은 사용되지 않는다.
 - 특정위치의 노드 번호는 새로운 노드가 추가 되어도 변하지 않는다.
 - 힙에서의 부모 노드와 자식 노드의 관계
 1) 왼쪽 자식의 인덱스 = (부모의 인덱스) * 2
 2) 오른쪽 자식의 인덱스 = (부모의 인덱스) * 2 + 1
 3) 부모의 인덱스 = (자식의 인덱스) / 2
 *****************************************************/

////////////////최대힙////////////////

#define MAX_ELEMENT 200 // 힙 안에 저장된 요소의 개수

typedef struct {
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

//힙 생성
HeapType heap1;

/*********************
 힙 삽입
 1. 힙에 새로운 요소가 들어오면, 일단 새로운 노드를 힙의 마지막 노드에 이어서 삽입한다.
 2. 새로운 노드를 부모 노드들과 교환해서 힙의 성질을 만족시킨다.
 
 - 인덱스 순으로 가장 마지막 위치에 이어서 새로운 요소 삽입
 - 부모 노드 < 삽입 노드 이면 교환
 *********************/

void insert_max_heap(HeapType *h, element item) {
    int i;
    i = ++(h->heap_size); //힙 크기를 하나 증가
    
    //i가 루트 노드(index:1)이 아니고, 삽입할 item의 값이 i의 부모노드(index:i/2)보다 크면
    while((i != 1) && (item.key > h->heap[i/2].key)) {
        //i번째 노드와 부모 노드를 교환한다.
        h->heap[i] = h->heap[i/2];
        //한 레벨 위로 올라간다.
        i = i/2;
    }
    h->heap[i] = item; //새로운 노드 삽입
}

/************************
 힙 삭제
 1. 최대힙에서 최대값은 루트 노드이므로 루트 노드가 삭제된다.
 - 최대 힙에서 삭제 연산은 최대값을 가진 요소를 삭제하는 것이다.
 2. 삭제된 루트 노드에는 힙의 마지막 노드를 가져온다.
 3. 힙을 재구성한다.
 ************************/
element delete_max_heap(HeapType *h) {
    int parent,child;
    element item, temp;
    
    item = h->heap[1]; // 루트 노드 값을 반환하기 위해 item에 할당
    temp = h->heap[(h->heap_size)--]; //마지막 노드를 temp에 할당하고 힙 크기를 하나 감소
    parent = 1;
    child = 2;
    
    while(child <= h->heap_size) {
        //현재 노드의 자식 노드 중 더 큰 자식 노드를 찾는다. (루트 노드의 왼쪽 자식 노드(index:2)부터 비교 시작)
        if( (child < h->heap_size) && ((h->heap[child].key) < h->heap[child+1].key) )
            child++;
        
        //더 큰 자식 노드보다 마지막 노드가 크면, while문 중지
        if( temp.key >= h->heap[child].key )
            break;
        
        //더 큰 자식 노드보다 마지막 노드가 작으면, 부모 노드와 더 큰 자식 노드를 교환
        h->heap[parent] = h->heap[child];
        //한 단계 아래로 이동
        parent = child;
        child = child * 2;
    }
    
    //마지막 노드를 재구성한 위치에 삽입
    h->heap[parent] = temp;
    //최대값(루트 노드 값)을 반환
    return item;
}


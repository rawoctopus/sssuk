//
//  Queue.c
//  DataStructure
//
//  Created by Sukho Lim on 27/06/2019.
//  Copyright © 2019 Sukho Lim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    Node *front; //맨 앞(꺼낼 위치)
    Node *rear; //맨 뒤(보관할 위치)
    int size; //보관 개수
}Queue;

void InitQueue(Queue *queue) {
    queue->front = queue->rear = NULL; //front, rear NULL로 설정
    queue->size = 0; //보관 개수 0으로 설정
}

int IsEmpty(Queue *queue) {
    if(queue->size == 0)
        return TRUE;
    return FALSE;
}

void Enqueue(Queue *queue, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node)); //새 노드 생성
    newNode->data = data; //새 노드에 enqueue 할 값 넣어줌
    newNode->next = NULL;
    
    if(IsEmpty(queue) == TRUE) //큐가 비어있으면(큐에 아무것도 없으면 처음 넣은 값이 맨 앞)
        queue->front = newNode;
    else //큐에 값이 있을 때
        queue->rear->next = newNode; //원래 맨 마지막에 있던 노드의 다음 노드가 새로운 노드
    
    queue->rear = newNode;
    queue->size++;
}

int Dequeue(Queue *queue) {
    if(IsEmpty(queue) == TRUE) //큐가 비어있으면
        return -1; //비어있다는 뜻으로 -1 리턴
    
    Node* front = queue->front;
    int data = front->data;
    queue->front = front->next;
    free(front);
    queue->size--;
    return data;
}

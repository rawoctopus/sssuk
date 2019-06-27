//
//  LinkedList.c
//  DataStructure
//
//  Created by Sukho Lim on 27/06/2019.
//  Copyright © 2019 Sukho Lim. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
}List;

void insertNode(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    
    //list 자체가 empty 상태면
    if(list->head == NULL && list->tail == NULL) {
        list->head = newNode;
        list->tail = newNode;
        return;
    }
    
    list->tail->next = newNode;
    list->tail = newNode;
}

void deleteNode(List *list) {
    Node *curNode = list->head;
    
    if(curNode == list->tail) {
        printf("list is empty!\n");
        return;
    }
    
    while(curNode->next->next != NULL)
        curNode = curNode->next;
    curNode->next = curNode->next->next;
    list->tail = curNode;
}

void printList(List *list) {
    Node *curNode = list->head;
    
    while(curNode != NULL) {
        printf("%d\n", curNode->data);
        curNode = curNode->next;
    }
}

List *initList(List *list) {
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int main() {
    List *list = (List*)malloc(sizeof(List));
    list = initList(list);
    
    insertNode(list, 3);
    insertNode(list, 5);
    insertNode(list, 1);
    
    printList(list);
    printf("-------------\n");
    
    deleteNode(list);
    printList(list);
    printf("-------------\n");
    
    deleteNode(list);
    printList(list);
    printf("---------------\n");
    
    deleteNode(list);
    printList(list);
    printf("--------------\n");
    
    return 0;
}

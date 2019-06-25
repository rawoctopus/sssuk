//
//  Stack.c
//  DataStructure
//
//  Created by Sukho Lim on 25/06/2019.
//  Copyright © 2019 Sukho Lim. All rights reserved.
//

#include "Stack.h"
#include <stdio.h>

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

int stack[MAX_SIZE];
int top = -1;

int IsEmpty() {
    if(top < 0)
        return TRUE;
    else
        return FALSE;
}

int IsFull() {
    if(top > MAX_SIZE)
        return TRUE;
    else
        return FALSE;
}

void Push(int value) {
    if(IsFull() == TRUE)
        printf("Stack is full!");
    else
        stack[++top] = value;
}

int Pop() {
    if(IsEmpty() == TRUE) {
        printf("Stack is empty!");
        return -1;
    }
    
    else
        return stack[top--];
}

int Top() {
    if(IsEmpty() == TRUE) {
        printf("Stack is empty!");
        return -1;
    }
    
    else
        return stack[top];
}

int main() {
    Push(3);
    Push(5);
    Push(1);
    
    for(int i = 0; i < 3; i++) {
        printf("%d\n", Pop());
    }
    
    return 0;
}

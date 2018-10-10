//
//  Queue.c
//  CStackDemo
//
//  Created by njim3 on 2018/9/28.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "Queue.h"
#include <malloc/malloc.h>
#include <stdlib.h>

StackQueue* createQueue(void) {
    StackQueue* queue = (StackQueue*)malloc(sizeof(StackQueue));
    if (!queue)
        return NULL;
    
    queue->stack1 = createStack();
    queue->stack2 = createStack();
    
    return queue;
}

void destroyQueue(StackQueue* queue) {
    destroyStack(queue->stack1);
    destroyStack(queue->stack2);
    
    free(queue);
}

void enQueue(StackQueue* queue, struct TreeNode* node) {
    pushStack(queue->stack1, node);
}

struct TreeNode* deQueue(StackQueue* queue) {
    if (isStackEmpty(queue->stack2)) {
        while (!isStackEmpty(queue->stack1)) {
            struct TreeNode* node = popStack(queue->stack1);
            
            pushStack(queue->stack2, node);
        }
    }
    
    return popStack(queue->stack2);
}

bool isQueueEmpty(StackQueue* queue) {
    return isStackEmpty(queue->stack1) && isStackEmpty(queue->stack2);
}

int sizeOfQueue(StackQueue* queue) {
    return sizeOfStack(queue->stack1) + sizeOfStack(queue->stack2);
}

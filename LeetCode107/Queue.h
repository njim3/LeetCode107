//
//  Queue.h
//  CStackDemo
//
//  Created by njim3 on 2018/9/28.
//  Copyright © 2018 njim3. All rights reserved.
//

#ifndef Queue_h
#define Queue_h
#include "Stack.h"

typedef struct StackQueue {
    TreeNodeStack* stack1;
    TreeNodeStack* stack2;
} StackQueue;

StackQueue* createQueue(void);
void destroyQueue(StackQueue* queue);
void enQueue(StackQueue* queue, struct TreeNode* node);
struct TreeNode* deQueue(StackQueue* queue);
bool isQueueEmpty(StackQueue* queue);
int sizeOfQueue(StackQueue* queue);

#endif /* Queue_h */

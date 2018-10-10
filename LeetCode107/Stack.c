//
//  Stack.c
//  CStackDemo
//
//  Created by njim3 on 2018/9/28.
//  Copyright © 2018 njim3. All rights reserved.
//

#include "Stack.h"
#include <malloc/malloc.h>
#include <stdlib.h>

TreeNodeStack* createStack(void) {
    TreeNodeStack* stack = (TreeNodeStack*)malloc(sizeof(TreeNodeStack));
    
    if (!stack)
        return NULL;
    
    stack->base = (struct TreeNode**)malloc(STACK_INITSIZE * sizeof(struct TreeNode*));
    
    if (!stack->base)
        return NULL;
    
    stack->top = 0;
    stack->size = STACK_INITSIZE;
    
    return stack;
}

bool enlargeStack(TreeNodeStack* stack) {
    if (!stack)
        return false;
    
    int newSize = STACK_INITSIZE + STACK_INCRESIZE;
    stack->base = (struct TreeNode**)realloc(stack->base,
                                sizeof(struct TreeNode**) * newSize);
    
    if (!stack->base)
        return false;
    
    stack->size = newSize;
    
    return true;
}

bool pushStack(TreeNodeStack* stack, struct TreeNode* node) {
    if (stack->top >= stack->size) {
        if (!enlargeStack(stack))
            return false;
    }
    
    stack->base[stack->top++] = node;
    
    return true;
}

struct TreeNode* popStack(TreeNodeStack* stack) {
    if (isStackEmpty(stack))
        return NULL;
    
    return stack->base[--stack->top];
}

int sizeOfStack(TreeNodeStack* stack) {
    return stack->top;
}

bool isStackEmpty(TreeNodeStack* stack) {
    return stack->top == 0;
}

void destroyStack(TreeNodeStack* stack) {
    free(stack->base);
    free(stack);
}

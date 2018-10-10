//
//  Stack.h
//  CStackDemo
//
//  Created by njim3 on 2018/9/28.
//  Copyright © 2018 njim3. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdbool.h>

#define STACK_INITSIZE          1000
#define STACK_INCRESIZE         100

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

typedef struct TreeNodeStack {
    struct TreeNode** base;
    
    int top;
    int size;
} TreeNodeStack;

TreeNodeStack* createStack(void);
bool enlargeStack(TreeNodeStack* stack);
bool pushStack(TreeNodeStack* stack, struct TreeNode* node);
struct TreeNode* popStack(TreeNodeStack* stack);
int sizeOfStack(TreeNodeStack* stack);
bool isStackEmpty(TreeNodeStack* stack);
void destroyStack(TreeNodeStack* stack);

#endif /* Stack_h */

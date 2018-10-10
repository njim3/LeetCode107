//
//  main.c
//  LeetCode107
//
//  Created by njim3 on 2018/10/9.
//  Copyright © 2018 njim3. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include <stdlib.h>

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize)
{
    if (!root) {
        (* columnSizes) = NULL;
        (* returnSize) = 0;
        
        return NULL;
    }
    
    StackQueue* queue = createQueue();
    
    TreeNodeStack* nodeValueStack = createStack();
    TreeNodeStack* layerCountStack = createStack();
    
    enQueue(queue, root);
    
    int nodesCount = 1;
    struct TreeNode* treeNode = NULL;
    
    while (!isQueueEmpty(queue)) {
        nodesCount = sizeOfQueue(queue);
        
        // count stack
        pushStack(layerCountStack, (struct TreeNode*)(intptr_t)nodesCount);
        
        for (int i = 0; i < nodesCount; ++i) {
            treeNode = deQueue(queue);
            
            if (treeNode->left)
                enQueue(queue, treeNode->left);
            
            if (treeNode->right)
                enQueue(queue, treeNode->right);
            
            pushStack(nodeValueStack, (struct TreeNode*)(intptr_t)treeNode->val);
        }
    }
    
    (* returnSize) = sizeOfStack(layerCountStack);
    (* columnSizes) = (int*)malloc(sizeof(int) * (* returnSize));
    
    int** returnArray = (int**)malloc(sizeof(int*) * (* returnSize));
    int j = 0;
    
    while (!isStackEmpty(layerCountStack)) {
        nodesCount = (int)(intptr_t)popStack(layerCountStack);
        (* columnSizes)[j] = nodesCount;
        
        int* curLayerValueArr = (int*)malloc(sizeof(int) * nodesCount);
        
        for (int i = nodesCount - 1; i >= 0; --i) {
            curLayerValueArr[i] = (int)(intptr_t)popStack(nodeValueStack);
        }
        
        returnArray[j] = curLayerValueArr;
        
        ++j;
    }
    
    destroyStack(layerCountStack);
    destroyStack(nodeValueStack);
    destroyQueue(queue);
    
    return returnArray;
}

int main(int argc, const char * argv[]) {
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* level11 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* level12 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* level121 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    struct TreeNode* level122 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    root->val = 3;
    root->left = level11;
    root->right = level12;
    
    level11->val = 9;
    level11->left = NULL;
    level11->right = NULL;
    
    level12->val = 20;
    level12->left = level121;
    level12->right = level122;
    
    level121->val = 15;
    level121->left = NULL;
    level121->right = NULL;
    
    level122->val = 7;
    level122->left = NULL;
    level122->right = NULL;
    
    int returnSize = 0;
    int* columnSizes = (int*)malloc(sizeof(int));
    int** returnArray = levelOrderBottom(root, &columnSizes, &returnSize);
    
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", returnArray[i][j]);
        }
        
        putchar('\n');
    }
    
    return 0;
}

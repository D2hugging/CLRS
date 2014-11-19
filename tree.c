#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "common.h"


struct binNode *newNode(int data)
{
    struct binNode *node = (struct binNode *)malloc(sizeof(struct binNode));
    if (!node)
        return NULL;
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

/* root - left subtree - right subtree */
void preorder(struct binNode *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* left subtree - root - right subtree */
void inorder(struct binNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

/* left subtree - right subtree - root */
void postorder(struct binNode *root)
{
     if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}

struct threadNode *leftmost(struct threadNode *root)
{
    if (root == NULL)
        return NULL;
    while (root->left){
        root = root->left;
    }
    return root;
}

void threadInorder(struct threadNode *root)
{
    // if (!root)
    //     return;
    struct threadNode *current = leftmost(root);
    while (current){
        printf("%d ", current->key);
        if (current->rightThread)
            current = current->right;
        else
            current = leftmost(current->right);
    }

    
}

struct threadNode *newThreadNode(int data)
{
    struct threadNode *node = (struct threadNode *)malloc(sizeof(struct threadNode));
    if (!node)
        return NULL;
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

int sizeTree(struct binNode *root)
{
    if (!root)
        return 0;
    return sizeTree(root->left) + sizeTree(root->right) + 1;
}

int identicalTrees(struct binNode *a, struct binNode *b)
{
    if (!a && !b)
        return 1;
    if (a && b)
        return (a->key == b->key) && identicalTrees(a->left,b->left) && identicalTrees(a->right,b->right);

    return 0;
}

int maxDepth(struct binNode *root)
{
    if (!root)
        return 0;
    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        return (lDepth > rDepth ? (lDepth + 1) : (rDepth + 1 ));
    }
}

void __deleteTree(struct binNode *root)
{
    if (!root)
        return;
    __deleteTree(root->left);
    __deleteTree(root->right);
    printf("\nDeleting node: %d", root->key);
    free(root);
}

void deleteTree(struct binNode **root_ref)
{
    __deleteTree(*root_ref);
    *root_ref = NULL;
}

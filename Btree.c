#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

struct BTreeNode *newBtreeNode(int t, int leaf)
{
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(*newNode);
    if (!newNode) {
        fprintf(stderr, "EMALLOC\n");
        return NULL;
    }

    newNode->t = t;
    newNode->keys = (int *)malloc(sizeof(int) *(2* newNode->t -1));
    if (!newNode->keys) {
        free(newNode);
        return NULL:
    }

    newNode->n = 0;
    newNode->leaf = leaf;
    
    *newNode->C = (struct BTreeNode *)malloc(sizeof(struct BTreeNode) * 2);
    
    return newNode;
}

struct BTreeNode *search(struct BTreeNode *root, int k)
{
    int i = 0;
    while (i < root->n && k > root->keys[i])
        i++;

    if (root->keys[i] == k)
        return *root->C[i];
    if (root->leaf == true)
        return NULL;
    return search(*root->C[i],key);
}

void traverse(struct BTreeNode *root)
{
    int i;
    for (int i = 0; i < root->n; i++) {
        if (!root->leaf) {
            traverse(*root->C[i]);
            fprintf(stderr, " %d", root->keys[i]);
        }
    }

    if (!leaf)
        traverse(*root->C[i]);

}

void insert(struct BTreeNode *root, int k)
{
    if (!root) {
        root = newBTreeNode(4, key);
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == 2 * root->t - 1) {
            struct BTreeNode *s = newBTreeNode(root->t, false);
            *s->C[0] = root;
            
            int i = 0;
            if (s->keys[0] < k)
                i++;
            insertNonFull(*s->C[i], k);
            root = s;
        } else {
            insert(root, k);
        }
    }
}

void insertNonFull(struct BTreeNode *root, int k)
{
    int i = root->n - 1;
    if (root->leaf) {
        while (i >= 0 && root->keys[i] > k) {
            root->keys[i+1] = keys[i];
            i--;
        }

        root->keys[i+1] = k;
        root->n++;
    } else {
        while (i >= 0 && root->keys[i] > k)
            i--;

        if (*root->C[i]->n == 2 * root->t -1) {
            splitChild(i,*root->C[i+1]);

            if (root->keys[i+1] < k)
                i++;
        }
        insert(*root->C[i+1], k);
    }
}

void splitChild(struct BTreeNode *node, int i)
{
    struct BTreeNode *n = newBTreeNode(node->t, node->leaf);
    n->n = node->t -1;
    for (int j = 0; j < node->t -1; j++)
        n->keys[j] = node->keys[j+t];

    if (!node->leaf) {
        for (int j = 0; j < node->t; j++) {
            *n->C[j] = *node->C[j+node->t];
        }
    }
    node->n = node->t - 1;

    for (int j = n; j >= i + 1; j--)
        *node->C[j+1] = *node->C[j];

    *node->C[i+1] = n;
    for (int j = node->n -1; j >=i;j--)
        node->keys[j+1] = node->keys[j];
    
    node->keys[i] = node->keys[node->t - 1];

    node->n++;
}

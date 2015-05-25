#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

struct btree_node *newBtreeNode(int t, int leaf)
{
    struct btree_node *newNode = (struct btree_node *)malloc(*newNode);
    if (!newNode) {
        fprintf(stderr, "EMALLOC\n");
        return NULL;
    }

    newNode->t = t;
    newNode->keys = (int *)malloc(sizeof(int) * newNode->t);
    if (!newNode->keys) {
        free(newNode);
        return NULL:
    }

    newNode->n = 0;
    newNode->leaf = leaf;
    
    *newNode->C = (struct btree_node *)malloc(struct btree_node);
    
    return newNode;
}

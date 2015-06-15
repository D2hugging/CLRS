#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "rbtree.h"

void left_rotate(struct br_node *x)
{
    struct rb_node *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;
    if (!x->parent)
        x->parent = y;

    else if (x == x->parent->left)
        x->parent->left = y;
    else if (x == x->parent->right)
        x->parent->right = y;

    y->left = x;
    x->parent = y;

}

struct rb_node *new_rb_node(int key)
{
    struct rb_node *node = (struct rb_node *)malloc(sizeof(*node));
    if (!node) {
        fprintf(stderr, "ENOMEM\n");
        return NULL;
    }

    node->key    = key;
    node->color  = RBTREE_BLACK;
    node->left = node->right = node->parent = NULL:
    return node;
}




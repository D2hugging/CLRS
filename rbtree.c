#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "rbtree.h"

void left_rotate(struct br_node **root, struct br_node *x)
{
    /* y指向x右子树 */
    struct rb_node *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;

    y->parent = x->parent;
    if (!x->parent)
        *root = y;

    else if (x == x->parent->left)
        x->parent->left = y;
    else if (x == x->parent->right)
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void right_rotate(struct rb_node **root, struct rb_tree *y)
{
    struct node *x = y->left;
    y->left = x->right;

    if (x->right)
        x->right->parent = y;

    x->parent = y->parent;
    if (!x->parent)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void rb_insert(struct rb_node **root, int key)
{
    /* allocate memory for new node */
    struct rb_node *z = (struct rb_node *)malloc(sizeof(*z));
    z->key = key;
    z->left = z->right = z->parent = NULL;

    if (*root == NULL) {
        z->color = BRTREE_BLACK;
        *root = z;
    } else {
        struct node *y = NULL;
        struct node *x = *root;

        while (x) {
            y = x;
            if (z->data < x->data)
                x = x->left;
            else
                x = x->right;
        }

        z->parent = y;
        if (z->data > y->data)
            y->right = z;
        else
            y->left = z;

        z->color = BRTREE_RED;
        rb_insert_fixup(root, z);    
    }
}

void rb_insert_fixup(struct rb_node **root, struct rb_node *z)
{
    while (z->parent->color == RBTREE_RED) {
        struct rb_node *y;
        if (z->parent == z->parent->parent->left) 
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

            
       if (y->color == RBTREE_RED) {
           y->color == RBTREE_BLACK;
           z->parent->color = RBTREE_BLACK;
           z->parent->parent->color = RBTREE_RED;
           z = z->parent->parent;
       } else {
           if (z->parent == z->parent->parent->left && z == z->parent->left) {
               swap(&z->parent->color, &z->parent->parent->color);
               right_rotate(root, z->parent->parent);
           }

           if (z->parent == z->parent->parent->left && z == z->parent->right) {
               swap(&z->color, &z->parent->parent->color);
               left_rotate(root, z->parent);
               right_rotate(root, z->parent->parent);
           }

           if (z->parent == z->parent->parent->right && z == z->parent->right) {
               swap(&z->parent->color, &z->parent->parent->color);
               left_rotate(root, z->parent->parent);           
           }
           
           if (z->parent == z->parent->parent->right && z == z->parent->left) {
               swap(&z->color, &z->parent->parent->color);
               right_rotate(root, z->parent);
               left_rotate(root, z->parent->parent);
           }
    }
    
    (*root)->color = RBTREE_BLACK;
}


struct rb_node *new_rb_node(int key)
{
    /* allocate memory for new node */
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




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "rbtree.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void left_rotate(struct rb_node **root, struct rb_node *x)
{
    /* y指向x右子树 */
    struct rb_node *y = x->right;
    x->right = y->left;
    if (x->right)
        x->right->parent = x;

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

void right_rotate(struct rb_node **root, struct rb_node *y)
{
    struct rb_node *x = y->left;
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

void rb_insert(struct rb_node **root, int data)
{
    /* allocate memory for new node */
    struct rb_node *z = (struct rb_node *)malloc(sizeof(*z));
    z->data = data;
    z->left = z->right = z->parent = NULL;

    if (*root == NULL) {
        z->color = RBTREE_BLACK;
        *root = z;
    } else {
        struct rb_node *y = NULL;
        struct rb_node *x = *root;

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

        z->color = RBTREE_RED;
        rb_insert_fixup(root, z);    
    }
}

void rb_insert_fixup(struct rb_node **root, struct rb_node *z)
{
    while (z != *root && z->parent->color == RBTREE_RED) {
        struct rb_node *y;
        if (z->parent == z->parent->parent->left) 
            y = z->parent->parent->right;
        else
            y = z->parent->parent->left;

            
        if (y->color == RBTREE_RED) {
            y->color = RBTREE_BLACK;
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
}

void rb_inorder(struct rb_node *root)
{
    if (root == NULL)
        return;
    rb_inorder(root->left);
    fprintf(stderr, "%d ", root->data);
    rb_inorder(root->right);
}

int main(void)
{
    struct rb_node *root = NULL;
    rb_insert(&root, 5);
    rb_insert(&root, 3);
    rb_insert(&root, 7);
    rb_insert(&root, 2);
    rb_insert(&root, 4);
    rb_insert(&root, 6);
    rb_insert(&root, 8);
    rb_insert(&root, 11);
    fprintf(stderr, "rbtree inorder traversal\n");
    rb_inorder(root);
    fprintf(stderr, "\n");
    return 0;
}


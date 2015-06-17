#ifndef __RBTREE_H__
#define __RBTREE_H__

#define RBTREE_BLACK 0
#define RBTREE_RED   1

struct rb_node {
    int color;
    int data;
    struct rb_node *left;
    struct rb_node *right;
    struct rb_node *parent;
};

struct rb_tree {
    struct rb_node *root;
};

void swap(int *, int *);
void left_rotate(struct rb_node **root, struct rb_node *x);
void right_rotate(struct rb_node **root, struct rb_node *x);
void rb_insert(struct rb_node **root, int key);
void rb_insert_fixup(struct rb_node **root, struct rb_node *z);
void rb_inorder(struct rb_node *root);
#endif

#ifndef __RBTREE_H__
#define __RBTREE_H__

#define RBTREE_BLACK 0
#define RBTREE_RED   1

struct rb_node {
    int color;
    int key;
    struct rb_node *left;
    struct rb_node *right;
    struct rb_node *parent;
};

struct rb_tree {
    struct rb_node *root;
};

struct rb_node *new_rb_node(int key);
struct rb_tree *new_rb_tree(void);
void left_rotate(struct br_node **root, struct br_node *x);
void right_rotate(struct br_node **root, struct br_node *x);
void br_insert(struct rb_node **root, int key);
void br_insert_fixup(struct rb_node **root, struct rb_node *z);

#endif

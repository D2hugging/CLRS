#ifndef __BTREE_H__
#define __BTREE_H__

struct btree_node {
    int     *keys;          /* array of keys */     
    int     t;              /* Minumim degree */
    struct  btree_node **C; /* array of child pointer */
    int     n;              /* current number of keys */
    int     leaf;           /* leaf or not */
};

struct btree_node *newBtreeNode(int t, int leaf);
#endif

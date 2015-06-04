#ifndef __BTREE_H__
#define __BTREE_H__

#define true  1
#define false 0
#define DEGREE 3

struct BTreeNode {
    int     *keys;          /* array of keys */     
    struct  BTreeNode **C; /* array of child pointer */
    int     nr;              /* current number of keys */
    int     leaf;           /* leaf or not */
};

struct BTree {
    int t;                  /* minimum degree */
    struct BTreeNode *root;
};

struct BTreeNode *newBTreeNode(void);
struct BTree *newBTree(int t);
struct BTreeNode *search(struct BTreeNode *, int);
void traverse(struct BTreeNode *);
void insert(struct BTree *, int);
void insertNonFull(struct BTreeNode *, int);
void splitChild(struct BTreeNode *, int);

#endif

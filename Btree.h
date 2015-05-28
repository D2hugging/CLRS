#ifndef __BTREE_H__
#define __BTREE_H__

#define true  1
#define false 0

struct BTreeNode {
    int     *keys;          /* array of keys */     
    int     t;              /* Minumim degree */
    struct  BTreeNode **C; /* array of child pointer */
    int     n;              /* current number of keys */
    int     leaf;           /* leaf or not */
};

struct BTreeNode *newBTreeNode(int t, int leaf);
struct BTreeNode *search(struct BTreeNode *, int);
void traverse(struct BTreeNode *);
void insert(struct BTreeNode *, int);
void insertNonFull(struct BTreeNode *, int);
void splitChild(struct BTreeNode *, int);

#endif

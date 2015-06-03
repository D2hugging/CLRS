#include <stdio.h>
#include <stdlib.h>
#include "Btree.h"

struct BTreeNode *newBTreeNode(void)
{
    struct BTreeNode *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
    if (!newNode) {
        fprintf(stderr, "EMALLOC\n");
        return NULL;
    }

    newNode->keys = (int *)malloc(sizeof(int) *(2*DEGREE -1));
    if (!newNode->keys) {
        free(newNode);
        return NULL;
    }

    newNode->nr = 0;
    newNode->leaf = true;
    
    newNode->C = (struct BTreeNode **)malloc(sizeof(struct BTreeNode *)*2*DEGREE);
    
    return newNode;
}

struct BTree *newBTree(int t)
{
    struct BTree *tree = (struct BTree *)malloc(sizeof(struct BTree));
    if (!tree) {
        fprintf(stderr, "EMALLOC\n");
        return NULL;
    }

    tree->t = t;
    tree->root = newBTreeNode();

    return tree;
}
struct BTreeNode *search(struct BTreeNode *x, int k)
{
    int i = 0;
    while (i < x->nr && k > x->keys[i])
        i++;

    if (x->keys[i] == k)
        return x->C[i];
    if (x->leaf)
        return NULL;
    return search(x->C[i], k);
}

void traverse(struct BTreeNode *x)
{
    int i = 0;
    for (i = 0; i < x->nr; i++) {
        if (!x->leaf) {
            traverse(x->C[i]);
            fprintf(stderr, " %d", x->keys[i]);
        }
    }

    if (!x->leaf)
        traverse(x->C[i]);

}

void insert(struct BTreeNode *x, int k)
{
        if (x->nr == 2 * DEGREE - 1) {
            struct BTreeNode *s = newBTreeNode();
            s->leaf = false;
            s->nr = 0;
            s->C[0] = x;
            x = s;

            splitChild(s, 0);
            insertNonFull(s, k);
        } else {
            insertNonFull(x, k);
        }
}

void insertNonFull(struct BTreeNode *x, int k)
{
    int i = x->nr - 1;
    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i+1] = x->keys[i];
            i--;
        }

        x->keys[i+1] = k;
        x->nr++;
    } else {
        while (i >= 0 && x->keys[i] > k)
            i--;
        i++;
        if (x->C[i]->nr == 2 * DEGREE -1) {
            splitChild(x, i);

            if (x->keys[i] < k)
                i++;
        }
        insertNonFull(x->C[i], k);
    }
}

void splitChild(struct BTreeNode *x, int i)
{
    struct BTreeNode *z = newBTreeNode();
    struct BTreeNode* y = x->C[i];
    z->leaf = y->leaf;
    z->nr = DEGREE-1;

    /* 修改被提升节点右边部分的keys，C */
    for (int j = 0; j < DEGREE -1; j++)
        z->keys[j] = y->keys[j + DEGREE];

    if (!y->leaf) {
        for (int j = 0; j < DEGREE; j++) {
            z->C[j] = y->C[j+DEGREE];
        }
    }
    /* 修改被提升节点左边部分keys的个数 */
    y->nr = DEGREE - 1;

    /*  */
    for (int j = x->nr + 1; j >= i + 1; j--)
        x->C[j+1] = x->C[j];

    /* 被提升节点指向右边节点 */
    x->C[i+1] = z;
    for (int j = x->nr -1; j >=i;j--)
        x->keys[j+1] = x->keys[j];
    
    /* 被提升节点keys赋值 */
    x->keys[i] = y->keys[DEGREE - 1];

    x->nr++;
}

int main(void)
{
    struct BTree *t = newBTree(3);
    insert(t->root, 10);
    insert(t->root, 20);
    insert(t->root, 5);
    insert(t->root, 6);
    insert(t->root, 12);
    insert(t->root, 30);
    insert(t->root, 7);
    insert(t->root, 17);

    traverse(t->root);
    int k = 6;
    if(!search(t->root, k))
        fprintf(stderr, "Not Preset\n");
    else
        fprintf(stderr, "Present\n");

    return 0;
}


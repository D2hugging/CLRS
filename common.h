#ifndef __GEEKSFORGEEKS__
#define __GEEKSFORGEEKS__

struct node
{
    int key;
    struct node *next;
};

struct binNode
{
	int key;
	struct binNode *left;
	struct binNode *right;
};

struct threadNode
{
	int key;
	struct threadNode *left;
	struct threadNode *right;
	int rightThread;
};

/* list */
void push(struct node **, int);
void printList(struct node *);
int  GetNth(struct node *, int);
void returnNth(struct node *, int, struct node **);
void deleteNode(struct node *);
void reverse(struct node **);
void recursiveReverse(struct node **);
int  detectLoop(struct node *, struct node **);
void pairWiseSwap(struct node *);
void swap(int *, int *);
void swapNode(struct node *, struct node *);
void deleteAlt(struct node *);
void rotate(struct node **, int);

/* tree */
struct binNode *newNode(int );
void preorder(struct binNode *);
void inorder(struct binNode *);
void postorder(struct binNode *);
struct threadNode *leftmost(struct threadNode *);
void threadInorder(struct threadNode *);
int sizeTree(struct binNode *);
int identicalTrees(struct binNode *, struct binNode *);
int maxDepth(struct binNode *);
void deleteTree(struct binNode **);
void __deleteTree(struct binNode *);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);


#endif

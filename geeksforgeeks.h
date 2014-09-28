#ifndef __GEEKSFORGEEKS__
#define __GEEKSFORGEEKS__

struct node
{
    int key;
    struct node *next;
};

struct bstNode
{
	int key;
	struct bstNode *left;
	struct bstNode *right;
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
struct bstNode *newNode(int );
void preorder(struct bstNode *);
void inorder(struct bstNode *);
void postorder(struct bstNode *);
struct threadNode *leftmost(struct threadNode *);
void threadInorder(struct threadNode *);

#endif

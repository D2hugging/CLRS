#ifndef __GEEKSFORGEEKS__
#define __GEEKSFORGEEKS__

struct node{
    int key;
    struct node *next;
};

void push(struct node **, int);
void printList(struct node *);
int  GetNth(struct node *, int);
void returnNth(struct node *, int, struct node **);
void deleteNode(struct node *);
void reverse(struct node **);
void recursiveReverse(struct node **);
int detectLoop(struct node *, struct node **);


#endif

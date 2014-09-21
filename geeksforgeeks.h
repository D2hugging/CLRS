#ifndef __GEEKSFORGEEKS__
#define __GEEKSFORGEEKS__

struct node{
    int key;
    struct node *next;
};

void push(struct node **, int);
void printList(struct node *);
int  GetNth(struct node *, int);
struct node *returnNth(struct node *, int);
void deleteNode(struct node *);

#endif

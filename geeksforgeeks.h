#ifndef __GEEKSFORGEEKS__
#define __GEEKSFORGEEKS__

struct node{
    int key;
    struct node *next;
};

void push(struct node **, int);
void print_list(struct node **);

#endif

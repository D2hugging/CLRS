#ifndef __GRAPH_H__
#define __GRAPH_H__

#define G_TRUE              1
#define G_FALSE             0

/* Graph */
struct adjListNode {
    int dest;
    struct adjListNode *next;
};

struct adjList {
    struct adjListNode *head;
};

struct Graph {
    int v;
    struct adjList *array;
};

/* Queue */
struct Queue {
    int front;
    int rear;
    int size;
    int capacity;
    int *array;
};

/* prototype */
struct Queue *newQueue(int);
int isFull(struct Queue *);
int isEmpty(struct Queue *);
void enQueue(struct Queue *, int);
int deQueue(struct Queue *);
int front(struct Queue *);
struct adjListNode *newAdjListNode(int dest);
struct Graph *newGraph(int v);
void addEdge(struct Graph *, int src, int dest);
void printGraph(struct Graph *);
void bfs(struct Graph *graph, int s);

#endif

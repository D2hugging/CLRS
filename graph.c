#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graph.h"


struct adjListNode *newAdjListNode(int dest)
{
    struct adjListNode *node = (struct adjListNode *)malloc(sizeof(*node));
    if (!node) 
        return NULL;
    node->dest = dest;
    node->next = NULL;
    return node;
}

struct Graph *newGraph(int v)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(*graph));
    if (!graph)
        return NULL;

    graph->array = (struct adjList *)malloc(sizeof(struct adjList) * v);
    if (!graph->array){
        fprintf(stderr,"EMALLOC\n");
        free((void *)graph);
        return NULL;
    }
    graph->v = v;
    for (int i=0; i<graph->v; i++)
        graph->array[i].head = NULL;

    return graph;
}

struct Queue *newQueue(int capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (!queue){
        fprintf(stderr,"[%s]EMALLOC\n",__FUNCTION__);
        return NULL;
    }
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->capacity = capacity;
    queue->array = (int *)malloc(sizeof(int)*capacity);
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return queue->size == 0;
}

int isFull(struct Queue *queue)
{
    return queue->size == queue->capacity;
}

void enQueue(struct Queue *queue, int s)
{
    if (isFull(queue)){
        fprintf(stderr, "[%s]EFULL\n", __FUNCTION__);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = s;
    queue->size++;
    fprintf(stderr, "[%s] %d enqueued to queue\n", __FUNCTION__, s);
}

int deQueue(struct Queue *queue)
{
    if (isEmpty(queue)){
        fprintf(stderr, "[%s]EEMPTY", __FUNCTION__);
        return INT_MIN;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    fprintf(stderr, "[%s] %d dequeued to queue\n", __FUNCTION__, item);
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue)){
        fprintf(stderr, "[%s]EEMPTY", __FUNCTION__);
        return INT_MIN;
    }
    return queue->array[queue->front];
}

void disposeQueue(struct Queue *queue)
{
    if (!queue)
        return;
    free(queue);
}

void addEdge(struct Graph *graph, int src, int dest)
{
    struct adjListNode *noded = newAdjListNode(dest);
    noded->next = graph->array[src].head;
    graph->array[src].head = noded;
    
    struct adjListNode *nodes = newAdjListNode(src);
    nodes->next = graph->array[dest].head;
    graph->array[dest].head = nodes;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->v; i++){
        fprintf(stderr, "Adjacency list of vertex %d\n head", i);
        while(graph->array[i].head){
            fprintf(stderr, "-> %d", graph->array[i].head->dest);
            graph->array[i].head = graph->array[i].head->next;
        }
        fprintf(stderr, "\n");
    }
}

void bfs(struct Graph *graph, int s)
{

    int visited[graph->v];
    for (int i = 0; i < graph->v; i++)
        visited[i] = G_FALSE;
    visited[s] = G_TRUE;
    
    struct Queue *queue = newQueue(10);
    enQueue(queue, s);
    
    fprintf(stderr, "BFS\n");
    while (!isEmpty(queue)) {
        int temp = deQueue(queue);
        fprintf(stderr, "%d\n", temp);
        while (graph->array[temp].head){
            if (!visited[graph->array[temp].head->dest]) {
                visited[graph->array[temp].head->dest] = G_TRUE;
                enQueue(queue,graph->array[temp].head->dest);
                graph->array[s].head = graph->array[s].head->next;
            }
        }
    }
    return;
}


int main(int argc, char **argv)
{
    int v = 5;
    struct Graph *graph = newGraph(v);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    bfs(graph, 2);
}


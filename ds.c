#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "geeksforgeeks.h"

void push(struct node **head_ref, int new_data)
{
    struct node *new_node =
        (struct node *)malloc(sizeof(struct node));

    new_node->key = new_data;
    new_node->next = *head_ref;

    *head_ref = new_node;
}

void printList(struct node *head)
{
    struct node *current = head;
    while(current){
        printf("%d->",current->key);
        current = current->next;
    }
    printf("NULL\n");
}

int GetNth(struct node *head, int index)
{
    struct node *current = head;
    int count = 0;

    if (!head)
        return -1;

    while(current){
        if (count == index){
            break;
        }
        count++;
        current = current->next;
    }
    return current->key;
}

struct node *returnNth(struct node *head, int index)
{
    if (!head)
        return NULL;
    int count = 0;
    struct node *current = head;
    while(current){
        if (count == index){
            return current;
        }
        count++;
        current = current->next;
    }
    exit(0);
}

void deleteNode(struct node *node_ptr)
{
    struct node *temp = node_ptr->next;
    node_ptr->key = temp->key;
    node_ptr->next = temp->next;
    free(temp);
}

void reverse(struct node **head_ref)
{
    if (*head_ref == NULL)
        return;

    struct node *current = *head_ref;
    struct node *prev = NULL;
    struct node *next;

    while (current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}


int main(int argc, char **argv)
{
    struct node *head_ref =NULL;

    push(&head_ref, 1);
    push(&head_ref, 2);
    push(&head_ref, 3);
    push(&head_ref, 4);
    push(&head_ref, 5);
    push(&head_ref, 6);
    push(&head_ref, 7);
    printList(head_ref);
    
    struct node *temp = returnNth(head_ref, 3);
    printList(temp);
    deleteNode(temp); 
    printList(head_ref);
    reverse(&head_ref);
    printList(head_ref);
    exit(0);
}




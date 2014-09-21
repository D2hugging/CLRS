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

void returnNth(struct node *head, int index, struct node **ret)
{
    if (!head)
        return;
    int count = 0;
    struct node *current = head;
    while(current){
        if (count == index){
            *ret = current;
        }
        count++;
        current = current->next;
    }
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

void recursiveReverse(struct node **head_ref)
{
    struct node *first = *head_ref;

    if (first == NULL)
        return;
    struct node *rest = first->next;
    if (rest == NULL)
        return;

    recursiveReverse(&rest);
    first->next->next = first;
    first->next = NULL;

    *head_ref = rest;
}

/* return 0 on seccuss,other on error */
int detectLoop(struct node *head, struct node **res)
{
    struct node *fast = head;
    struct node *slow = head;

    if (head == NULL)
        return -1;
    while (fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow){
            *res = fast;
            return 0;
        }
    }
    return -2;
}


int main(int argc, char **argv)
{
    struct node *head_ref =NULL;
    struct node *ret = NULL;
    struct node *retNth = NULL;

    push(&head_ref, 1);
    push(&head_ref, 2);
    push(&head_ref, 3);
    push(&head_ref, 4);
    push(&head_ref, 5);
    push(&head_ref, 6);
    push(&head_ref, 7);
    printList(head_ref);
    
    returnNth(head_ref, 3, &retNth);
    printf("3th %d\n", retNth->key);
    deleteNode(retNth); 
    printList(head_ref);
    reverse(&head_ref);
    printList(head_ref);
    recursiveReverse(&head_ref);
    printList(head_ref);
    head_ref->next->next->next->next = head_ref;
    int loop = detectLoop(head_ref,&ret);
    printf("loop %d, loop->key %d\n",loop,ret->key);

    exit(0);
}


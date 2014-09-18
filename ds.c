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

void print_list(struct node *head_ref)
{
    if (!head_ref)
        return;
    while(head_ref){
        printf("%d->",head_ref->key);
        head_ref = head_ref->next;
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


int main(int argc, char **argv)
{
    struct node *head_ref =NULL;

    push(&head_ref, 1);
    push(&head_ref, 2);
    push(&head_ref, 3);
    push(&head_ref, 4);
    print_list(head_ref);
    printf("%dth is %d\n", 3, GetNth(head_ref, 3));
    exit(0);
}




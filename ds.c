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

void print_list(struct node **head_ref)
{
    while(*head_ref){
        printf("%d->",*head_ref->key);
        (*head_ref)++;
    }
    pirntf("->NULL\n");
}

int main(int argc, char **argv)
{
    struct node *head_ref =NULL;

    push(&head_ref, 1);
    print_list(&head_ref);

    exit(0);
}




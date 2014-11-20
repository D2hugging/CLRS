#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "common.h"




void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
 /*   struct node *head_ref =NULL;

    push(&head_ref, 1);
    push(&head_ref, 2);
    push(&head_ref, 3);
    push(&head_ref, 4);
    push(&head_ref, 5);
    printList(head_ref);
 */   
    // struct binNode *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    int arr[] = {4,13,19, 1,5, 9,25,18};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertSort(arr, size);
    printArray(arr, size);
    exit(0);
}


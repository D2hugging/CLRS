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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapNode(struct node  *prev, struct node *current)
{
    prev->next = current->next;
    current->next = prev;
}

void pairWiseSwap(struct node *head)
{
    struct node *current = head;
    struct node *next_next;
    
    while (current && current->next){
        next_next = current->next->next;
        swapNode(current, current->next);
        current = next_next;
    }
}

void deleteAlt(struct node *head)
{
    struct node *current = head;
    struct node *prev = head;
    while ( prev && prev->next){
        current = prev->next;
        prev->next = current->next;
        free(current);
        prev = prev->next;
    }
}

void rotate(struct node **head_ref, int k)
{
    struct node *current = *head_ref;

    int count = 1;
    if (k == 0)
        return;
    if (count < k && current){
        current = current->next;
        count++;
    }
    if (!current)
        return;
    struct node *kthNode = current;
    while (current->next){
        current = current->next;
    }
    current->next = *head_ref;
    *head_ref = kthNode->next;
    kthNode->next = NULL;
}

struct bstNode *newNode(int data)
{
    struct bstNode *node = (struct bstNode *)malloc(sizeof(struct bstNode));
    if (!node)
        return NULL;
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

/* root - left subtree - right subtree */
void preorder(struct bstNode *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* left subtree - root - right subtree */
void inorder(struct bstNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

/* left subtree - right subtree - root */
void postorder(struct bstNode *root)
{
     if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);
}

struct threadNode *leftmost(struct threadNode *root)
{
    if (root == NULL)
        return NULL;
    while (root->left){
        root = root->left;
    }
    return root;
}

void threadInorder(struct threadNode *root)
{
    // if (!root)
    //     return;
    struct threadNode *current = leftmost(root);
    while (current){
        printf("%d ", current->key);
        if (current->rightThread)
            current = current->right;
        else
            current = leftmost(current->right);
    }

    
}

struct threadNode *newThreadNode(int data)
{
    struct threadNode *node = (struct threadNode *)malloc(sizeof(struct threadNode));
    if (!node)
        return NULL;
    node->key = data;
    node->left = node->right = NULL;
    return node;
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
    struct threadNode *root = newThreadNode(1);
    root->left = newThreadNode(2);
    root->right = newThreadNode(3);
    root->left->left = newThreadNode(4);
    root->left->right = newThreadNode(5);
    root->right->left = newThreadNode(6);
    threadInorder(root);
    exit(0);
}


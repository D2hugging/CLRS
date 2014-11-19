#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "common.h"

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

struct binNode *newNode(int data)
{
    struct binNode *node = (struct binNode *)malloc(sizeof(struct binNode));
    if (!node)
        return NULL;
    node->key = data;
    node->left = node->right = NULL;
    return node;
}

/* root - left subtree - right subtree */
void preorder(struct binNode *root)
{
    if (!root)
        return;
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

/* left subtree - root - right subtree */
void inorder(struct binNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

/* left subtree - right subtree - root */
void postorder(struct binNode *root)
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

int sizeTree(struct binNode *root)
{
    if (!root)
        return 0;
    return sizeTree(root->left) + sizeTree(root->right) + 1;
}

int identicalTrees(struct binNode *a, struct binNode *b)
{
    if (!a && !b)
        return 1;
    if (a && b)
        return (a->key == b->key) && identicalTrees(a->left,b->left) && identicalTrees(a->right,b->right);

    return 0;
}

int maxDepth(struct binNode *root)
{
    if (!root)
        return 0;
    else {
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);

        return (lDepth > rDepth ? (lDepth + 1) : (rDepth + 1 ));
    }
}

void __deleteTree(struct binNode *root)
{
    if (!root)
        return;
    __deleteTree(root->left);
    __deleteTree(root->right);
    printf("\nDeleting node: %d", root->key);
    free(root);
}

void deleteTree(struct binNode **root_ref)
{
    __deleteTree(*root_ref);
    *root_ref = NULL;
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right){
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i,j;
    int k = left;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; ++i)
    {
        a1[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        a2[j] = arr[mid + 1 +j];
    }
    i = j = 0;
    
    while (i < n1 && j < n2){
        if (a1[i] <= a2[j]){
            arr[k] = a1[i];
            k++;
            i++;
        } else {
            arr[k] = a2[j];
            k++;
            j++;
        }

    }

    while (i < n1){
        arr[k] = a1[i];
        k++;
        i++;
    }
    while (j < n2){
        arr[k] = a2[j];
        k++;
        j++;
    }
}

struct MaxHeap *buildMaxHeap(int arr[], int size)
{
    struct MaxHeap *maxheap = (struct MaxHeap *)malloc(sizeof(struct MaxHeap));
    if (!maxheap)
        return NULL;
    maxheap->size = size;
    maxheap->array = arr;

    for (int i = (maxheap->size - 2)/2; i >= 0; --i){
        maxHeapify(maxheap, i);
    }
    return maxheap;
}

int maxHeapify(struct MaxHeap *maxheap, int index)
{
    if (!maxheap)
        return -1;
    int largest = index;
    int left = Left(index);
    int right = Right(index);
    if ((left < maxheap->size) && (maxheap->array[left] > maxheap->array[largest])){
        largest = left;
    }
    if ((right < maxheap->size) && (maxheap->array[right] > maxheap->array[largest])){
        largest = right;
    }
    if (largest != index){
        swap(&maxheap->array[largest], &maxheap->array[index]);
        maxHeapify(maxheap, largest);
    }
    return 0;
}

int heapSort(int arr[], int size)
{
    struct MaxHeap *maxheap = buildMaxHeap(arr, size);
    if (!maxheap)
        return -1;
    printArray(maxheap->array, maxheap->size);
    while(maxheap->size > 1){
        /* swap the root and the last,then reduce the size by one*/
        swap(&maxheap->array[0], &maxheap->array[--maxheap->size]);
        /* maxHeapify the new size heap */
        maxHeapify(maxheap, 0);        
    }
    return 0;
}

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
    heapSort(arr, size);
    printArray(arr, size);
    exit(0);
}


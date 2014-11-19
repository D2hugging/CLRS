#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "common.h"

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
    int left = (index << 1) + 1;
    int right = (index + 1) << 1;
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

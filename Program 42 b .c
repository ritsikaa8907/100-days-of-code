//The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- Max Heap Functions ---------- */

void maxHeapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1)/2] < heap[index]) {
        swap(&heap[(index - 1)/2], &heap[index]);
        index = (index - 1)/2;
    }
}

void maxHeapifyDown(int heap[], int size, int index) {
    int largest = index;

    while (1) {
        int left = 2*index + 1;
        int right = 2*index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(&heap[index], &heap[largest]);
            index = largest;
        } else
            break;
    }
}

/* ---------- Min Heap Functions ---------- */

void minHeapifyUp(int heap[], int index) {
    while (index > 0 && heap[(index - 1)/2] > heap[index]) {
        swap(&heap[(index - 1)/2], &heap[index]);
        index = (index - 1)/2;
    }
}

void minHeapifyDown(int heap[], int size, int index) {
    int smallest = index;

    while (1) {
        int left = 2*index + 1;
        int right = 2*index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else
            break;
    }
}

/* ---------- Initialize ---------- */

MedianFinder* medianFinderCreate() {
    MedianFinder* obj = (MedianFinder*)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

/* ---------- Add Number ---------- */

void addNum(MedianFinder* obj, int num) {

    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        obj->maxHeap[obj->maxSize++] = num;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    } else {
        obj->minHeap[obj->minSize++] = num;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    }

    /* Balance Heaps */

    if (obj->maxSize > obj->minSize + 1) {
        int val = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];
        maxHeapifyDown(obj->maxHeap, obj->maxSize, 0);

        obj->minHeap[obj->minSize++] = val;
        minHeapifyUp(obj->minHeap, obj->minSize - 1);
    }

    if (obj->minSize > obj->maxSize) {
        int val = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[--obj->minSize];
        minHeapifyDown(obj->minHeap, obj->minSize, 0);

        obj->maxHeap[obj->maxSize++] = val;
        maxHeapifyUp(obj->maxHeap, obj->maxSize - 1);
    }
}

/* ---------- Find Median ---------- */

double findMedian(MedianFinder* obj) {

    if (obj->maxSize == obj->minSize)
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;

    return obj->maxHeap[0];
}

/* ---------- Free Memory ---------- */

void medianFinderFree(MedianFinder* obj) {
    free(obj);
}

//Implement the KthLargest class:
//KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
//int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
#include <stdlib.h>

typedef struct {
    int *heap;
    int size;
    int k;
} KthLargest;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(KthLargest* obj, int i) {
    while (i > 0 && obj->heap[(i - 1) / 2] > obj->heap[i]) {
        swap(&obj->heap[(i - 1) / 2], &obj->heap[i]);
        i = (i - 1) / 2;
    }
}

void heapifyDown(KthLargest* obj, int i) {
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < obj->size && obj->heap[left] < obj->heap[smallest])
            smallest = left;

        if (right < obj->size && obj->heap[right] < obj->heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(&obj->heap[i], &obj->heap[smallest]);
        i = smallest;
    }
}

KthLargest* kthLargestCreate(int k, int* nums, int numsSize) {
    KthLargest* obj = (KthLargest*)malloc(sizeof(KthLargest));
    obj->heap = (int*)malloc(sizeof(int) * k);
    obj->size = 0;
    obj->k = k;

    for (int i = 0; i < numsSize; i++) {
        int val = nums[i];

        if (obj->size < k) {
            obj->heap[obj->size] = val;
            heapifyUp(obj, obj->size);
            obj->size++;
        } else if (val > obj->heap[0]) {
            obj->heap[0] = val;
            heapifyDown(obj, 0);
        }
    }

    return obj;
}

int kthLargestAdd(KthLargest* obj, int val) {
    if (obj->size < obj->k) {
        obj->heap[obj->size] = val;
        heapifyUp(obj, obj->size);
        obj->size++;
    } else if (val > obj->heap[0]) {
        obj->heap[0] = val;
        heapifyDown(obj, 0);
    }

    return obj->heap[0];
}

void kthLargestFree(KthLargest* obj) {
    free(obj->heap);
    free(obj);
}

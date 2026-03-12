//Implement a Min Heap using an array where the smallest element is always at the root.
#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(int index) {
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}

void heapifyDown(int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

void insert(int value) {
    if (size == MAX) {
        printf("Heap Overflow\n");
        return;
    }

    heap[size] = value;
    heapifyUp(size);
    size++;
}

int deleteMin() {
    if (size == 0) {
        printf("Heap Underflow\n");
        return -1;
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return root;
}

void display() {
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    insert(20);
    insert(10);
    insert(30);
    insert(5);
    insert(15);

    printf("Heap elements: ");
    display();

    printf("Deleted min: %d\n", deleteMin());

    printf("Heap after deletion: ");
    display();

    return 0;
}

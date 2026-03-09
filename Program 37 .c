//Implement a Priority Queue using an array. An element with smaller value has higher priority.
#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int value) {
    int i = size - 1;

    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1] = value;
    size++;
}

int delete() {
    if (size == 0) {
        printf("Queue Underflow\n");
        return -1;
    }

    int value = pq[0];

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    return value;
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    insert(5);

    printf("Priority Queue: ");
    display();

    printf("Deleted: %d\n", delete());

    printf("After Deletion: ");
    display();

    return 0;
}

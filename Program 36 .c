// Circular Queue Using Array - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (rear == NULL) {
        rear = newNode;
        rear->next = rear;
    } else {
        newNode->next = rear->next;
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (rear == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = rear->next;

    if (rear->next == rear) {
        printf("Deleted: %d\n", temp->data);
        free(temp);
        rear = NULL;
    } else {
        printf("Deleted: %d\n", temp->data);
        rear->next = temp->next;
        free(temp);
    }
}

void display() {
    if (rear == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = rear->next;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != rear->next);

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();
    display();

    return 0;
}

// Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int length = getLength(head);
    k = k % length;

    if (k == 0)
        return head;

    struct Node* temp = head;
    int stepsToNewHead = length - k;

    for (int i = 1; i < stepsToNewHead; i++)
        temp = temp->next;

    struct Node* newHead = temp->next;
    temp->next = NULL;

    struct Node* tail = newHead;
    while (tail->next != NULL)
        tail = tail->next;

    tail->next = head;

    return newHead;
}

void traverse(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);
    head = insertEnd(head, 5);

    printf("Original List:\n");
    traverse(head);

    int k = 2;
    head = rotateRight(head, k);

    printf("After Rotating by %d:\n", k);
    traverse(head);

    return 0;
}

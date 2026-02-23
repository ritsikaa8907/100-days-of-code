// Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.
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

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeSorted(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeSorted(l1, l2->next);
    }

    return result;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node* merged = mergeSorted(list1, list2);

    printf("Merged List: ");
    display(merged);

    return 0;
}

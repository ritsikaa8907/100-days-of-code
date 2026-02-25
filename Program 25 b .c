//Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

struct ListNode *detectCycle(struct ListNode *head) {
    
    if (head == NULL || head->next == NULL)
        return NULL;
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        
        if (slow == fast)
            break;
    }
    
    if (fast == NULL || fast->next == NULL)
        return NULL;
    
    slow = head;
    
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    
    return slow;
}

int main() {
    struct ListNode *head = NULL, *temp = NULL;
    
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    head->next->next->next->next->next = head->next->next;
    
    struct ListNode *cycleStart = detectCycle(head);
    
    if (cycleStart != NULL)
        printf("Cycle starts at node with value: %d\n", cycleStart->val);
    else
        printf("No cycle detected\n");
    
    return 0;
}

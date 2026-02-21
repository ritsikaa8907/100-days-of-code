//Given the head of a singly linked list, return the middle node of the linked list.

struct ListNode* middleNode(struct ListNode* head) {
    
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

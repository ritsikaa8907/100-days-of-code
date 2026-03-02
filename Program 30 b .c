//You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
struct ListNode* reverse(struct ListNode* head) {
    struct ListNode* prev = NULL;
    while (head) {
        struct ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    l1 = reverse(l1);
    l2 = reverse(l2);
    
    int carry = 0;
    struct ListNode* head = NULL;
    
    while (l1 || l2 || carry) {
        int sum = carry;
        
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = sum % 10;
        node->next = head;
        head = node;
        
        carry = sum / 10;
    }
    
    return head;
}

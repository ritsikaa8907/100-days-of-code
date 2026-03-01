//Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return true;

    struct ListNode *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *prev = NULL, *curr = slow, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    struct ListNode *first = head;
    struct ListNode *second = prev;

    while (second != NULL) {
        if (first->val != second->val)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

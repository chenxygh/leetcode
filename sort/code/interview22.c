/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// assume all test cases are available
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *p = head;
    for (int i = 0; i < k - 1; ++i) {
        p = p->next;
    }
    while (p->next) {
        p = p->next;
        head = head->next;
    }
    return head;
}

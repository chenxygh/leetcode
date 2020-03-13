/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    int i = 1;
    struct ListNode *p = head, *q = head;
    while (q && i < k) {
        ++i;
        q = q->next;
    }
    while (q->next) {
        p = p->next;
        q = q->next;
    }

    return p->val;
}

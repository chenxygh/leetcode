/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    while (q && q->next) {
        p = p->next;
        q = q->next->next;
        if (p == q) {
            while (p != head) {
                head = head->next;
                p = p->next;
            }
            return p;
        }
    }
    return NULL;
}

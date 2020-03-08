/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = head;
    struct ListNode *p, *q, *r;
    p = L;
    q = p->next;
    r = q? q->next: q;

    int del = 0;
    while (r) {
        if (q->val == r->val) {
            del = 1;
            r = r->next;
            free(q->next);
            q->next = r;
        } else {
            if (del) {
                del = 0;
                p->next = r;
                free(q);
                q = r;
                r =  q->next;
            } else {
                p = q;
                q = r;
                r = q->next;
            }
        }
    }
    if (del) {
        p->next = r;
        free(q);
    }

    head = L->next;
    free(L);
    return head;
}

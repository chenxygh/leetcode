/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = head;
    struct ListNode *p, *r;
    p = L;
    r = p->next;

    while (r) {
        if (r->val == val) {
            p->next = r->next;
            free(r);
        } else {
            p = r;
        }
        r = p->next;
    }

    p = L->next;
    free(L);
    return p;
}

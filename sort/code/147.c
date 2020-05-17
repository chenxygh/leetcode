/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *L = (struct ListNode *)malloc (sizeof (struct ListNode)), *p = head->next, *q, *pre;
    q = pre = L->next = head;
    
    while (p) {
        int val = p->val;
        q = L;
        while (q->next != p && val >= q->next->val) q = q->next;
        if (q->next == p) {
            pre = pre->next;
        } else {
            pre->next = p->next;
            p->next = q->next;
            q->next = p;
        }
        p = pre->next;
    }

    head = L->next;
    free(L);
    return head;
}

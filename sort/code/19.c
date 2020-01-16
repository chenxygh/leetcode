/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *pre = (struct ListNode *)malloc(sizeof(struct ListNode));
    pre->next = head;
    struct ListNode *p = head;
    struct ListNode *q = head;
    head = pre;

    while (--n) q = q->next;
    
    while (q->next) {
        pre = p;
        p = p->next;
        q = q->next;
    }
    pre->next = p->next;
    free(p);
    p = head->next;
    free(head);

    return p;
}

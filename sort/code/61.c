/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) return NULL;
    struct ListNode *p = head;
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    k %= length;
    if (k == 0) return head;

    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
    L->next = head;
    struct ListNode *q = p = head;
    struct ListNode *pre = L;
    while (--k) q = q->next;
    while (q->next) {
        pre = p;
        p = p->next;
        q = q->next;
    }
    pre->next = NULL;
    q->next = L->next;
    free(L);
    return p;
}

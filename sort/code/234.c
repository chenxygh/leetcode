/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) return true;
    struct ListNode *p = head, *q = head, *L = (struct ListNode *) malloc (sizeof(struct ListNode));
    L->next = NULL;
    while (q && q->next) {
        struct ListNode *temp = p;
        p = p->next;
        q = q->next->next;
        temp->next = L->next;
        L->next = temp;
    }
    if (q) p = p->next;
    q = L->next;
    free(L);
    while (p && p->val == q->val) {
        p = p->next;
        q = q->next;
    }
    return p == NULL;
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode *p = head;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            p->next = l1;
            p = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            p = l2;
            l2 = l2->next;
        }
    }

    p->next = l1? l1: l2;
    p = head->next;
    free(head);

    return p;
}

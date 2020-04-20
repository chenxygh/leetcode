/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// struct ListNode* reverseList(struct ListNode* head){
//     struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
//     L->next = NULL;
//     while (head) {
//         struct ListNode *p = head->next;
//         head->next = L->next;
//         L->next = head;
//         head = p;
//     }
//     head = L->next;
//     free(L);
//     return head;
// }

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = NULL, *q = head, *r = head->next;
    q->next = p;
    while (r) {
        p = q;
        q = r;
        r = r->next;
        q->next = p;
    }
    return q;
}

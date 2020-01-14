/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// struct ListNode* reverseList(struct ListNode* head){
//     struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
//     p->next = NULL;

//     struct ListNode *q = head;
//     while (head) {
//         q = head;
//         head = head->next;
//         q->next = p->next;
//         p->next = q;
//     }
    
//     q = p->next;
//     free(p);

//     return q;
// }

// struct ListNode* reverseList(struct ListNode* head){
//     if (head == NULL) return NULL;
//     struct ListNode *p, *q, *r;
//     p = NULL;
//     q = head;
//     r = head->next;
//     q->next = p;
//     while (r) {
//         p = q;
//         q = r;
//         r = r->next;
//         q->next = p;
//     }

//     return q;
// }

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return p;
}

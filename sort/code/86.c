/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *la = (struct ListNode *)malloc(sizeof(struct ListNode)), *rearA = la;
    struct ListNode *lb = (struct ListNode *)malloc(sizeof(struct ListNode)), *rearB = lb;
    la->next = lb->next = NULL;
    while (head) {
        if (head->val < x) {
            rearA = rearA->next = head;
            head = head->next;
        } else {
            rearB = rearB->next = head;
            head = head->next;
        }
    }
    rearA->next = lb->next;
    rearB->next = NULL;
    head = la->next;
    free(la);
    free(lb);
    return head;
}

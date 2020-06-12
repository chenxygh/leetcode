/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *) malloc (sizeof (struct ListNode)), *rear = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            rear = rear->next = l1;
            l1 = l1->next;
        } else {
            rear = rear->next = l2;
            l2 = l2->next;
        }
    }
    rear->next = l1? l1: l2;
    rear = head->next;
    free(head);
    return rear;
}

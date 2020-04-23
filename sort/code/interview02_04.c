/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *l1 = (struct ListNode *)malloc (sizeof(struct  ListNode)), *rear1 = l1;
    struct ListNode *l2 = (struct ListNode *)malloc (sizeof(struct  ListNode)), *rear2 = l2;
    l1->next = l2->next = NULL;
    while (head) {
        if (head->val < x) {
            rear1 = rear1->next = head;
        } else {
            rear2 = rear2->next = head;
        }
        head = head->next;
    }
    rear1->next = l2->next;
    rear2->next = NULL;
    head = l1->next;
    free(l1);
    free(l2);
    return head;
}

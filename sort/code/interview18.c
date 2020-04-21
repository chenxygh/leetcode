/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode)), *pre = L;
    L->next = head;
    while (head && head->val != val) {
        pre = head;
        head = head->next;
    }
    if (head) {
        pre->next = head->next;
    }
    head = L->next;
    free(L);
    return head;
}

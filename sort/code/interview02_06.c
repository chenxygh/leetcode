/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// method 1: array
// bool isPalindrome(struct ListNode* head){
//     int nums[100000], n = 0;
//     while (head) {
//         nums[n++] = head->val;
//         head = head->next;
//     }
//     int i = 0, j = n - 1;
//     for (; i < j && nums[i] == nums[j]; ++i, --j);
//     return i >= j;
// }

// method 2: double points
bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) return true;
    struct ListNode *L = (struct ListNode *)malloc(sizeof (struct ListNode)), *p = head, *q = head;
    L->next = NULL;
    while (q && q->next) {
        struct ListNode *temp = p;
        p = p->next;
        q = q->next->next;
        temp->next = L->next;
        L->next = temp;        
    }
    if (q) {
        p = p->next;
    }
    q = L->next;
    free(L);
    while (q && (p->val == q->val)) {
        p = p->next;
        q = q->next;
    }
    return !q;
}

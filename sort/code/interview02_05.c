/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear = head;
    head->next = NULL;
    int carry = 0;
    while (l1 && l2) {
        int val = l1->val + l2->val + carry;
        carry = val / 10;
        l1->val = val % 10;
        rear = rear->next = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    l1 = l1? l1: l2;
    while (l1) {
        int val = l1->val + carry;
        carry = val / 10;
        l1->val = val % 10;
        rear = rear->next = l1;
        l1 = l1->next;
    }
    if (carry) {
        rear = rear->next = (struct ListNode *)malloc(sizeof (struct ListNode));
        rear->val = carry;
    }
    rear->next = NULL;
    l1 = head;
    head = head->next;
    free(l1);
    return head;    
}

// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)), *p = NULL;
//     head->next = NULL;
//     int nums[100], top_1 = -1, top_2 = 100;
//     while (l1 && l2) {
//         nums[++top_1] = l1->val;
//         nums[--top_2] = l2->val;
//         l1 = l1->next;
//         l2 = l2->next;
//     }
//     while (l1) {
//         nums[++top_1] = l1->val;
//         l1 = l1->next;
//     }
//     while (l2) {
//         nums[--top_2] = l2->val;
//         l2 = l2->next;
//     }

//     int carry = 0;
//     while (top_1 != -1 && top_2 != 100) {
//         int val = nums[top_1--] + nums[top_2++] + carry;
//         carry = val / 10;
//         p = (struct ListNode *)malloc (sizeof(struct ListNode));
//         p->val = val % 10;
//         p->next = head->next;
//         head->next = p;
//     }
//     l1 = l1? l1: l2;
//     while (top_1 != -1) {
//         int val = nums[top_1--] + carry;
//         carry = val / 10;
//         p = (struct ListNode *)malloc (sizeof(struct ListNode));
//         p->val = val % 10;
//         p->next = head->next;
//         head->next = p;
//     }
//     while (top_2 != 100) {
//         int val = nums[top_2++] + carry;
//         carry = val / 10;
//         p = (struct ListNode *)malloc (sizeof(struct ListNode));
//         p->val = val % 10;
//         p->next = head->next;
//         head->next = p;
//     }
//     if (carry) {
//          p = (struct ListNode *)malloc (sizeof(struct ListNode));
//         p->val = carry;
//         p->next = head->next;
//         head->next = p;
//     }
//     p = head;
//     head = head->next;
//     free(p);
//     return head;    
// }

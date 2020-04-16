/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// 头插法
struct ListNode *reverse_1 (struct ListNode *l) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;
    
    while (l) {
        struct ListNode *p = l;
        l = l->next;
        p->next = head->next;
        head->next = p;
    }
    struct ListNode *p = head;
    head = head->next;
    free(p);
    return head;
}

// 原地掉头
struct ListNode *reverse_2 (struct ListNode *l) {
    if (l == NULL || l->next == NULL) return l;
    struct ListNode *p = NULL, *q = l, *r = l->next;
    while (r) {
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }
    q->next = p;
    return q;
}

// method 1: reverse ListNode
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     struct ListNode * (*reverse) (struct ListNode *) = reverse_2;
    
//     l1 = reverse (l1);
//     l2 = reverse (l2);
//     int carry = 0;
//     struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
//     head->next = NULL;
//     while (l1 && l2) {
//         int val = l1->val + l2->val + carry;
//         l1->val = val % 10;
//         carry = val / 10;
//         struct ListNode *p = l1;
//         l1 = l1->next;
//         l2 = l2->next;
//         p->next = head->next;
//         head->next = p;
//     }
//     struct ListNode *q = l1? l1: l2;
//     while (q) {
//         int val  = q->val + carry;
//         q->val = val % 10;
//         carry = val / 10;
//         struct ListNode *p = q;
//         q = q->next;
//         p->next = head->next;
//         head->next = p;
//     }
//     if (carry) {
//         q = (struct ListNode *)malloc(sizeof(struct ListNode));
//         q->val = carry;
//         q->next = head->next;
//         head->next = q;
//     }
//     q = head;
//     head = head->next;
//     free (q);
//     return head;
// }

// method 2: stack
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int stack[1000], n = 1000;
    int top1 = -1, top2 = n;
    while (l1 && l2) {
        stack[++top1] = l1->val;
        stack[--top2] = l2->val;
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1) {
        stack[++top1] = l1->val;
        l1 = l1->next;
    }
    while (l2) {
        stack[--top2] = l2->val;
        l2 = l2->next;
    }
    int carry = 0;
    struct ListNode *head = (struct ListNode *)malloc(sizeof (struct ListNode));
    head->next = NULL;
    while (top1 != -1 && top2 != n) {
        int val = stack[top1--] + stack[top2++] + carry;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = val % 10;
        carry = val / 10;
        p->next = head->next;
        head->next = p;
    }
    while (top1 != -1) {
        int val = stack[top1--] + carry;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = val % 10;
        carry = val / 10;
        p->next = head->next;
        head->next = p;
    }
    while (top2 != n) {
        int val = stack[top2++] + carry;
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = val % 10;
        carry = val / 10;
        p->next = head->next;
        head->next = p;
    }
    if (carry) {
        struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = carry;
        p->next = head->next;
        head->next = p;
    }
    struct ListNode *p = head;
    head = head->next;
    free(p);
    return head;
}

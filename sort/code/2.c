// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *p = head;
    int count = 0;

    while (l1 && l2) {
        int sum = l1->val + l2->val + count;
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = sum % 10;
        p->next = q;
        p = q;
        count = sum / 10;

        l1 = l1->next;
        l2 = l2->next;
    }
    struct ListNode *s = l1? l1: l2;
    while (count && s) {
        int sum = (s? s->val: 0) + count;
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = sum % 10;
        p->next = q;
        p = q;
        count = sum / 10;

        s = s->next;
    }
    if (count) {
        struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = 1;
        p->next = q;
        p = q;
        p->next = NULL;
    } else if (s) {
        p->next = s;
    } else {
        p->next = NULL;
    }

    p = head->next;
    free(head);

    return p;
}

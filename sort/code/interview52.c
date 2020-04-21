/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int getLength (struct ListNode *head) {
    int cnt = 0;
    while (head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int ALen = getLength (headA);
    int BLen = getLength (headB);
    int n = 0;
    struct ListNode *p = NULL, *q = NULL;
    if (ALen > BLen) {
        n = ALen - BLen;
        p = headA;
        q = headB;
    } else {
        n = BLen - ALen;
        p = headB;
        q = headA;
    }
    while (n--) {
        p = p->next;
    }
    while (p && p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}

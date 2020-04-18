/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// method 1: array
// void reorderList(struct ListNode* head){
//     if (head == NULL || head->next == NULL || head->next->next == NULL) return;
//     struct ListNode *nodes[100000];
//     int length = 0;
//     while (head) {
//         nodes[length++] = head;
//         head = head->next;
//     }
//     int i = 0, j = length - 1;
//     for (; i < j; ++i, --j) {
//         nodes[j]->next = nodes[i]->next;
//         nodes[i]->next = nodes[j];
//     }
//     nodes[i]->next = NULL;
// }

// method 2: reverse
// struct ListNode *reverse (struct ListNode *head) {
//     struct ListNode *L = (struct ListNode *)malloc(sizeof(struct ListNode));
//     L->next = NULL;
//     while (head) {
//         struct ListNode *temp = head->next;
//         head->next = L->next;
//         L->next = head;
//         head = temp;
//     }
//     head = L->next;
//     free(L);
//     return head;
// }
// void reorderList(struct ListNode* head){
//     if (head == NULL || head->next == NULL || head->next->next == NULL) return;
//     struct ListNode *p = head, *q = head, *pre = NULL;
//     while (q && q->next) {
//         pre = p;
//         p = p->next;
//         q = q->next->next;
//     }
//     pre->next = NULL;
//     q = reverse (p);
//     p = head;
//     while (p) {
//         struct ListNode *temp = q->next;
//         q->next = p->next;
//         p->next = q;
//         pre = q;
//         p = q->next;
//         q = temp;
//     }
//     pre->next = q;
// }

// method 3: recursion
struct ListNode *recursion (struct ListNode *head, int length) {
    if (length == 0) return NULL;
    if (length == 1) return head;
    if (length == 2) return head->next;
    struct ListNode *tail = recursion (head->next, length - 2);
    struct ListNode *temp = tail->next;
    tail->next = temp->next;
    temp->next = head->next;
    head->next = temp;
    return tail;
}
void reorderList(struct ListNode* head){
    int length = 0;
    struct ListNode *p = head;
    while (p) {
        ++length;
        p = p->next;
    }
    recursion (head, length);
}

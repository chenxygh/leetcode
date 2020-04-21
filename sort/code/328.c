/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// struct ListNode* oddEvenList(struct ListNode* head){
//     if (head == NULL || head->next == NULL) return head;
//     struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear1 = l1;
//     struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear2 = l2;
//     int cnt = 0;
//     while (head) {        
//         if (++cnt % 2) {
//             rear1 = rear1->next = head;
//         } else {
//             rear2 = rear2->next = head;
//         }
//         head = head->next;
//     }
//     rear1->next = l2->next;
//     rear2->next = NULL;
//     rear1 = l1->next;
//     free(l1);
//     free(l2);
//     return rear1;
// }

struct ListNode* oddEvenList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *l1 = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear1 = l1;
    struct ListNode *l2 = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear2 = l2;
    while (head && head->next) {
        rear1 = rear1->next = head;
        rear2 = rear2->next = head->next;
        head = head->next->next;
    }
    rear1 = head? rear1->next = head: rear1;
    rear1->next = l2->next;
    rear2->next = NULL;
    rear1 = l1->next;
    free(l1);
    free(l2);
    return rear1;
}

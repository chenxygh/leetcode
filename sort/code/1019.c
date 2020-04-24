/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct elem {
    int val;
    int index;
} elem;

int getLength (struct ListNode *head) {
    int cnt = 0;
    while (head) {
        ++cnt;
        head = head->next;
    }
    return cnt;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize){
    int n = getLength (head);
    int *res = (int *)malloc(sizeof(int) * n), top = -1;
    elem nums[n];    
    
    for (int i = 0; head;) {
        if (top == -1 || nums[top].val >= head->val) {
            nums[++top].val = head->val;
            nums[top].index = i++;
            head = head->next;
        } else {
            res[nums[top--].index] = head->val;
        }
    }
    while (top != -1) {
        res[nums[top--].index] = 0;
    }
    returnSize[0] = n;
    return res;
}

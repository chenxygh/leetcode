#include <stdio.h>
#include <stdlib.h>

void Print (struct ListNode *);

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *merge_ite (struct ListNode *la, struct ListNode *lb, struct ListNode **tail) {
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode)), *rear = head;
    rear->next = NULL;
    while (la && lb) {
        if (la->val > lb->val) {
            rear = rear->next = lb;
            lb = lb->next;
        } else {
            rear = rear->next = la;
            la = la->next;
        }
    }
    rear->next = la? la: lb;
    while (rear->next) {
        rear = rear->next;
    }
    *tail = rear;
    rear = head->next;
    free(head);
    return rear;
}

// method 2: iteration
struct ListNode* sortList(struct ListNode* head){
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *p, *q, *L = (struct ListNode *)malloc(sizeof(struct ListNode)), *pre = L, *rear, *store;
    store = p = q = rear = NULL;
    L->next = head;
    int length = 0;
    while (head) {
        ++length;
        head = head->next;
    }
    for (int i = 1; i < length; i *= 2) {
        pre = L;

        while (pre->next) {
            rear = p = pre->next;
            int j = 0;
            for (; j < i && rear->next; ++j) {
                store = rear;
                rear = rear->next;
            }
            if (j < i) break;
            store->next = NULL;
            j = 0;
            q = rear;
            for (; rear && j < i; ++j) rear = rear->next;
            store = rear;
            struct ListNode *tail = NULL;
            rear->next = NULL;

            pre->next = merge_ite (p, q, &tail);
            Print ()

            pre = tail;
            pre->next = store;
        }
    }
    pre = L->next;
    free(L);
    return pre;
}

void Print (struct ListNode *p) {
	while (p) {
		printf("%d\n", p->val);
		p = p->next;
	}
}

int main(int argc, char const *argv[])
{
	struct ListNode* head = (struct ListNode *)malloc (sizeof (struct ListNode)), *rear = head;
	head->next = NULL;
	int nums[] = {4, 2, 1, 3};
	for (int i = 0; i < 4; ++i) {
		rear = rear->next = (struct ListNode *)malloc (sizeof (struct ListNode));
		rear->val = nums[i];
	}
	rear->next = NULL;

	sortList (head->next);

	return 0;
}

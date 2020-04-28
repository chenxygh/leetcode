/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// void recoverTree(struct TreeNode* root){
//     struct TreeNode *stack[100], *first, *second, *pre, *next;
//     first = second = pre = next = NULL;
//     int top = -1, n = 0;
//     while (top != -1 || root) {
//         if (root) {
//             stack[++top] = root;
//             root = root->left;
//         } else {
//             root = stack[top--];
//             if (pre && pre->val >= root->val) {
//                 if (first == NULL) {
//                     first = pre;
//                     next = root;
//                 } else {
//                     second = root;
//                     break;
//                 }
//             }
//             pre = root;
//             root = root->right;
//         }
//     }

//     second = second? second: next;
//     int temp = first->val;
//     first->val = second->val;
//     second->val = temp;
// }

void visit (struct TreeNode *pre, struct TreeNode *cur, struct TreeNode **first, struct TreeNode **second, struct TreeNode **next) {
    if (pre && pre->val >= cur->val) {
        if (first[0] == NULL) {
            first[0] = pre;
            next[0] = cur;
        } else {
            second[0] = cur;
        }
    }
}
void recoverTree(struct TreeNode* root){
    struct TreeNode *cur = root, *first, *second, *pre, *next;
    first = second = pre = next = NULL;
    while (cur) {
        if (cur->left) {
            struct TreeNode *temp = cur->left;
            while (temp->right && temp->right != cur) {
                temp = temp->right;
            }
            if (temp->right) {
                // visit (cur)
                if (second == NULL) {
                    visit (pre, cur, &first, &second, &next);
                }
                temp->right = NULL;
                pre = cur;
                cur = cur->right;
            } else {
                temp->right = cur;
                cur = cur->left;
            }
        } else {
            if (second == NULL) {
                visit (pre, cur, &first, &second, &next);
            }
            pre = cur;
            cur = cur->right;
        }
    }
    second = second? second: next;
    int temp = second->val;
    second->val = first->val;
    first->val = temp;
}

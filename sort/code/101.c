/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror (struct TreeNode *root1, struct TreeNode *root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return root1->val == root2->val && isMirror (root1->left, root2->right) && isMirror (root1->right, root2->left);
}

bool isSymmetric(struct TreeNode* root){
    return isMirror (root? root->left: root, root? root->right: root);
}

// bool isSymmetric(struct TreeNode* root){
//     struct TreeNode *Queue[1000];
//     int front = 0, rear = 0;
//     Queue[rear++] = root;
//     Queue[rear++] = root;

//     while (front < rear) {
//         struct TreeNode *t1 = Queue[front++];
//         struct TreeNode *t2 = Queue[front++];
//         if (t1 == NULL && t2 == NULL) continue;
//         if (t1 == NULL || t2 == NULL) return false;
//         if (t1->val != t2->val) return false;
//         Queue[rear++] = t1->left;
//         Queue[rear++] = t2->right;
//         Queue[rear++] = t1->right;
//         Queue[rear++] = t2->left;
//     }

//     return true;
// }

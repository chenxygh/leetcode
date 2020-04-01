/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


// int sumNumbers(struct TreeNode* root){
//     struct TreeNode *Stack_Nodes[100];
//     struct TreeNode *pre = NULL;
//     int Stack_Nums[100];
//     Stack_Nums[0] = 0;
//     int top = 0, sum = 0;
    
//     while (top != 0 || root) {
//         if (root) {
//             Stack_Nodes[++top] = root;
//             Stack_Nums[top] = Stack_Nums[top - 1] * 10 + root->val;
//             root = root->left;
//         } else {
//             root = Stack_Nodes[top];
//             if (root->right && root->right != pre) {
//                 root = root->right;
//             } else {
//                 if (root->left == NULL && root->right == NULL) sum += Stack_Nums[top];
//                 --top;
//                 pre = root;
//                 root = NULL;
//             }
//         }
//     }

//     return sum;
// }

void preOrder (struct TreeNode *root, int num, int *res) {
    if (root) {
        num = num * 10 + root->val;
        preOrder (root->left, num, res);
        preOrder (root->right, num, res);
        if (root->left == NULL && root->right == NULL) res[0] += num;
    }
}

int sumNumbers(struct TreeNode* root){
    int sum = 0;
    preOrder (root, 0, &sum);

    return sum;
}

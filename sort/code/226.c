/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// post order
// struct TreeNode* mirrorTree(struct TreeNode* root){
//     if (root) {
//         mirrorTree (root->left);
//         mirrorTree (root->right);
//         struct TreeNode *temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//     }
//     return root;
// }

// pre order
// struct TreeNode* mirrorTree(struct TreeNode* root){
//     if (root) {
//         struct TreeNode *temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//         mirrorTree (root->left);
//         mirrorTree (root->right);
//     }
//     return root;
// }

// in order
// struct TreeNode* mirrorTree(struct TreeNode* root){
//     if (root) {
//         mirrorTree (root->left);
//         struct TreeNode *temp = root->left;
//         root->left = root->right;
//         root->right = temp;
//         mirrorTree (root->left);
//     }
//     return root;
// }

// level order
struct TreeNode* mirrorTree(struct TreeNode* root){
    struct TreeNode *Queue[100];
    int front = 0, rear = 0;
    Queue[root? rear++: rear] = root;

    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        // 先存再交换， 与先交换再存， 无所谓， 皆可
        // if (p->left) Queue[rear++] = p->left;
        // if (p->right) Queue[rear++] = p->right;

        struct TreeNode *temp = p->left;
        p->left = p->right;
        p->right = temp;

        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;
    }

    return root;
}

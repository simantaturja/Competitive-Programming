/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    void traversal(TreeNode *root, int which) {
        if (root->left == NULL && root->right == NULL && !which) {
            sum += root->val;
        }
        if (root->left != NULL) {
            traversal(root->left, 0);
        }
        if (root->right != NULL) {
            traversal(root->right, 1);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        traversal(root, -1);
        return sum;
    }
};

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
    int add = 0, cnt = 0;
    vector <TreeNode*> nodes;
    void countPath(TreeNode* node, int sum) {
        add += node->val;
        if (add == sum) ++cnt;
        if (node->left != NULL) {
            countPath(node->left, sum);
        }
        if (node->right != NULL) {
            countPath(node->right, sum);
        }
        add -= node->val;
    }
    void traversal(TreeNode* node) {
        nodes.push_back(node);
        if (node->left != NULL) traversal(node->left);
        if (node->right != NULL) traversal(node->right);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        traversal(root);
        int sz = (int)nodes.size();
        for (int i = 0; i < sz; ++i) {
            add = 0;
            countPath(nodes[i], sum);
        }
        return cnt;
    }
};
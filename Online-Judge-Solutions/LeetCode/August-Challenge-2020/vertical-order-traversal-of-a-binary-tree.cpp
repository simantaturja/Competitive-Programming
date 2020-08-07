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
    vector <pair <int, int> > mp[5000];
    void inOrderTraversal(TreeNode* node, int x, int y) {
        if (node->left != NULL) {
            inOrderTraversal(node->left, x-1, y-1);
        }
        mp[1000+x].emplace_back(node->val, y);
        if (node->right != NULL) {
            inOrderTraversal(node->right, x+1, y-1);
        }
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inOrderTraversal(root, 0, 0);
        vector <vector <int> > ans;
        for (int i = 0; i <= 3000; ++i) {
            if (mp[i].size() > 0) {
                int sz = (int)mp[i].size();
                vector <int> temp;
                sort(mp[i].begin(), mp[i].end(), [](const pair <int, int> &a, const pair <int, int> &b) {
                    if (a.second == b.second) return a.first < b.first;
                    return a.second > b.second;
                });
                for (int j = 0; j < sz; ++j) {
                    temp.push_back(mp[i][j].first);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
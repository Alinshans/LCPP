// Title: Binary Tree Inorder Traversal
// Language: C++
// Runtime: 3 ms
// Submitted: 2018/3/30

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        auto cur = root;
        
        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            }
            else {
                auto t = s.top();
                v.push_back(t->val);
                s.pop();
                cur = t->right;
            }
        }
        return v;
    }
};

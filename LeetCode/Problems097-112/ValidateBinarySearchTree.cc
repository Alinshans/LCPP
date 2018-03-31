// Title: Validate Binary Search Tree
// Language: C++
// Runtime: 12 ms
// Submitted: 2018/4/1

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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* pre = nullptr;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (pre && root->val <= pre->val) return false;
            pre = root;
            root = root->right;
        }
        return true;
    }
};

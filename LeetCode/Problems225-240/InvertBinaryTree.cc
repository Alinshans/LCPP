// Title: Invert Binary Tree
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/7/2

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
	TreeNode* invertTree(TreeNode* root) {
		if (root)
		{
			if (root->left && root->right)
			{
				TreeNode *t = root->left;
				root->left = root->right;
				root->right = t;
				invertTree(root->left);
				invertTree(root->right);
			}
			else if (root->left && !root->right)
			{
				root->right = root->left;
				root->left = NULL;
				invertTree(root->right);
			}
			else if (!root->left && root->right)
			{
				root->left = root->right;
				root->right = NULL;
				invertTree(root->left);
			}
		}
		return root;
	}
};

// Title: Lowest Common Ancestor of a Binary Search Tree
// Language: C++
// Runtime: 40 ms
// Submitted: 2016/7/12

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
	vector<TreeNode *> v1;
	vector<TreeNode *> v2;
	void dfs(TreeNode* root, TreeNode* t, vector<TreeNode *> &v)
	{
		v.push_back(root);
		if (root->val == t->val) return;
		else if (root->val < t->val) dfs(root->right, t, v);
		else dfs(root->left, t, v);
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		dfs(root, p, v1);
		dfs(root, q, v2);
		TreeNode *anc;
		for (int i = 0; i < v1.size() && i < v2.size(); i++)
		{
			if (v1[i]->val == v2[i]->val)    anc = v1[i];
		}
		return anc;
	}
};

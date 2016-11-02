// Title: Path Sum
// Language: C++
// Runtime: 12 ms
// Submitted: 2016/7/12

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root)   return 0;
		if (root->val == sum && !root->left && !root->right)    return 1;
		sum -= root->val;
		if (root->left)
			if (hasPathSum(root->left, sum))     return 1;
		if (root->right)
			if (hasPathSum(root->right, sum))    return 1;
		return 0;
	}
};

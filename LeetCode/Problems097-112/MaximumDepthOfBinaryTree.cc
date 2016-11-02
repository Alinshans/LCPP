// Title: Maximum Depth of Binary Tree
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/2

class Solution {
public:
	int ans = 0;
	int dep = 1;
	int maxDepth(TreeNode* root) {
		if (root)
		{
			if (root->left)
			{
				++dep;
				maxDepth(root->left);
				--dep;
			}
			if (root->right)
			{
				++dep;
				maxDepth(root->right);
				--dep;
			}
			return ans = ans>dep ? ans : dep;
		}
		else return 0;
	}
};

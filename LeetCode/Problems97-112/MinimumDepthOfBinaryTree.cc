// Title: Minimum Depth of Binary Tree
// Language: C++
// Runtime: 12 ms
// Submitted: 2016/7/12

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)   return 0;
		int ld = minDepth(root->left);
		int rd = minDepth(root->right);
		if (!ld && !rd)  return 1;
		if (!ld)     ld = INT_MAX;
		if (!rd)     rd = INT_MAX;
		return min(ld, rd) + 1;
	}
};

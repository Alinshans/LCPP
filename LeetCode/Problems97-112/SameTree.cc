// Title: Same Tree
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/7/12

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)    return 1;
		if (p && q && p->val == q->val)
		{
			if (isSameTree(p->left, q->left))
				if (isSameTree(p->right, q->right))
					return 1;
		}
		return 0;
	}
};

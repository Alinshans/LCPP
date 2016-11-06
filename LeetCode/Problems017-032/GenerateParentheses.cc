// Title:  Generate Parentheses
// Language: C++
// Runtime: 3 ms
// Submitted: 2016/11/6

class Solution {
public:
	void doSth(vector<string>& ans, int l, int r, string str) {
		if (r < l)   return;
		if (!l && !r)    ans.push_back(str);
		if (l)   doSth(ans, l - 1, r, str + "(");
		if (r)   doSth(ans, l, r - 1, str + ")");
	}
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		if (!n)  return ans;
		doSth(ans, n, n, "");
		return ans;
	}
};

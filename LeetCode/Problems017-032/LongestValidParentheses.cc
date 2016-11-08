// Title: Longest Valid Parentheses
// Language: C++
// Runtime: 13 ms
// Submitted: 2016/11/8

class Solution {
public:
	int longestValidParentheses(string s) {
		if (!s.length()) return 0;
		stack<int> st;
		int ans = 0, start = -1;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') st.push(i);
			else {
				if (!st.size())
					start = i;
				else {
					st.pop();
					if (!st.size())
						ans = max(ans, i - start);
					else
						ans = max(ans, i - st.top());
				}
			}
		}
		return ans;
	}
};

// Title: Valid Parentheses
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/7/19

class Solution {
public:
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ')' || s[i] == ']' || s[i] == '}')
			{
				if (st.empty())     return false;
				else
				{
					if ((st.top() == '(' && s[i] != ')') || (st.top() == '[' && s[i] != ']') || (st.top() == '{' && s[i] != '}'))     return false;
					st.pop();
				}
			}
			else    st.push(s[i]);
		}
		return st.empty();
	}
};

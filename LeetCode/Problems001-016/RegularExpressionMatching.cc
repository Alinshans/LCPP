// Title:  Regular Expression Matching
// Language: C++
// Runtime: 146 ms
// Submitted: 2016/11/5

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p == "")  return s == "";
		int i = 0;
		if (p[1] == '*') {
			while (s[i] && p[0] == '.' || s[i] == p[0]) {
				if (isMatch(s.substr(i), p.substr(2)))  return true;
				++i;
			}
			return isMatch(s.substr(i), p.substr(2));
		}
		else if (s[i] && p[0] == '.' || s[i] == p[0])
			return isMatch(s.substr(1), p.substr(1));
		return false;
	}
};

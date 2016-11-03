// Title: Longest Palindromic Substring
// Language: C++
// Runtime: 36 ms
// Submitted: 2016/11/3

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.length() == 1 || s.length() == 2) return s;
		int i, j, near, start = 0, maxlen = 0, len = s.length();
		for (i = 0; i < len - 1; ++i) {
			int k = i;
			while (s[++k] == s[i]);
			near = k - i - 1;
			for (j = 1; i - j >= 0 && i + j + near <len; ++j)
				if (s[i - j] != s[i + j + near])   break;
			if (near > maxlen) {
				maxlen = near + 1;
				start = i;
			}
			if (2 * j + near - 1 > maxlen) {
				maxlen = 2 * j + near - 1;
				start = i - j + 1;
			}
		}
		return s.substr(start, maxlen);
	}
};

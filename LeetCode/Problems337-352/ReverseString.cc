// Title: Reverse String
// Language: C++
// Runtime: 12 ms
// Submitted: 2016/7/12

class Solution {
public:
	string reverseString(string &s) {
		int i, j;
		for (i = 0, j = s.length() - 1; i < j; i++, j--)
			swap(s[i], s[j]);
		return s;
	}
};

// Language: C++
// Runtime: 13 ms
// Submitted: 2016/11/2
class Solution {
public:
	string reverseString(string s) {
		reverse(s.begin(), s.end());
		return s;
	}
};

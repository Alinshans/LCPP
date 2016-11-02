// Title: Valid Anagram
// Language: C++
// Runtime: 78 ms
// Submitted: 2016/7/2

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.length() != t.length())    return 0;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s.compare(t) == 0 ? 1 : 0;
	}
};

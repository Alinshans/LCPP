// Title: Longest Substring Without Repeating Characters
// Language: C++
// Runtime: 13 ms
// Submitted: 2016/11/3

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const int len = s.length();
		int first[len + 1], next[len];
		int hash[128];
		memset(hash, len, sizeof(hash));
		first[len] = len;
		for (int i = len - 1; i >= 0; --i) {
			next[i] = hash[s[i]];
			hash[s[i]] = i;
			first[i] = min(next[i], first[i + 1]);
		}
		int maxlen = 0;
		for (int i = 0; i < len; ++i)
			maxlen = max(maxlen, first[i] - i);
		return maxlen;
	}
};

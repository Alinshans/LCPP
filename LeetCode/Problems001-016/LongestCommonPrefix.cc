// Title: Longest Common Prefix
// Language: C++
// Runtime: 3 ms
// Submitted: 2016/11/5

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		const int size = strs.size();
		if (!size)   return string("");
		if (size == 1)   return strs[0];
		int cnt = 0;
		for (; ; ++cnt) {
			const char ch = strs[size >> 1][cnt];
			for (int i = 0, j = size - 1; i < j; ++i, --j) {
				if (strs[i][cnt] != ch || strs[j][cnt] != ch)
					return strs[0].substr(0, cnt);
			}
		}
		return strs[0];
	}
};

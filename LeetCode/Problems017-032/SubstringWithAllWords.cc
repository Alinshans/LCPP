// Title: Substring with Concatenation of All Words
// Language: C++
// Runtime: 483 ms
// Submitted: 2016/11/8

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		const int len = words[0].length();
		const int size = words.size();
		if (!size || s.length() < len * size)    return vector<int>();
		vector<int> ans;
		map<string, int> m;
		map<string, int> w;
		for (int i = 0; i < size; ++i) ++w[words[i]];
		for (int i = 0; i <= s.length() - size * len; ++i) {
			if (w.find(s.substr(i, len)) != w.end()) {
				m.clear();
				++m[s.substr(i, len)];
				int j = 1;
				for (; j < size; ++j) {
					string str = s.substr(i + j * len, len);
					if (w.find(str) == w.end() || ++m[str] > w[str])
						break;
				}
				if (j == size) ans.push_back(i);
			}
		}
		return ans;
	}
};

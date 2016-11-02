// Title: Excel Sheet Column Number
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/2

class Solution {
public:
	int titleToNumber(string s) {
		int ans = 0;
		for (int i = 0; i < s.length(); i++)
		{
			ans += (s[i] - 'A' + 1) * pow(26, s.length() - i - 1);
		}
		return ans;
	}
};

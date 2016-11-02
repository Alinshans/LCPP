// Title: Number of 1 Bits
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/2

class Solution {
public:
	int hammingWeight(uint32_t n) {
		vector<int> v;
		int ans = 0;
		while (n)
		{
			v.push_back(n % 2);
			n /= 2;
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i])    ans++;
		}
		return ans;
	}
};

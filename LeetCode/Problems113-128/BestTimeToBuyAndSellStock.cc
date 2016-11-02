// Title: Best Time to Buy and Sell Stock
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/2

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int m = 1000000;
		int ans = 0;
		if (prices.size() < 2)   return 0;
		for (int i = 0; i < prices.size() - 1; i++)
		{
			m = min(m, prices[i]);
			ans = max(ans, prices[i + 1] - m);
		}
		return ans;
	}
};

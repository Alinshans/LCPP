// Title: Plus One
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/7/12

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int c = 1;
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			int s = digits[i] + c;
			c = s / 10;
			digits[i] = s % 10;
			if (!c)  break;
		}
		if (c)   digits.insert(digits.begin(), 1);
		return digits;
	}
};

// Title: Reverse Integer 
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/12

class Solution {
public:
	int reverse(int x) {
		bool sign = x > 0;
		long long ans = 0;
		x = abs(x);
		while (x)
		{
			ans = ans * 10 + x % 10;
			if (ans < INT_MIN || ans > INT_MAX)  return 0;
			x /= 10;
		}
		return sign ? ans : ans * -1;
	}
};
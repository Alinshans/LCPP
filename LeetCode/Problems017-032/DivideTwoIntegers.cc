// Title:  Divide Two Integers
// Language: C++
// Runtime: 6 ms
// Submitted: 2016/11/7

class Solution {
public:
	int divide(int dividend, int divisor) {
		long long m = abs((long long)dividend), n = abs((long long)divisor), ans = 0;
		if (m < n)   return 0;
		while (m >= n) {
			long long tmp = n, multip = 1;
			while (m >(tmp << 1)) {
				tmp <<= 1;
				multip <<= 1;
			}
			ans += multip;
			m -= tmp;
		}
		if ((dividend < 0) ^ (divisor < 0)) ans = -ans;
		return ans > INT_MAX ? INT_MAX : ans;
	}
};

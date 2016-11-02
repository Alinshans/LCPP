// Title: Sum of Two Integers
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/7/12

class Solution {
public:
	int getSum(int a, int b) {
		int sum = 0;
		int carry = 0;
		do {
			sum = a ^ b;
			carry = (a & b) << 1;
			a = sum;
			b = carry;
		} while (carry != 0);
		return sum;
	}
};

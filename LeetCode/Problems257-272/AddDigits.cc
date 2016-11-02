// Title: Add Digits
// Language: C++
// Runtime: 10 ms
// Submitted: 2016/7/2

class Solution {
public:
	int addDigits(int num) {
		return (num - 1) % 9 + 1;
	}
};


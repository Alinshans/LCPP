// Title: Power of Four
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/8/2

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
	}
};

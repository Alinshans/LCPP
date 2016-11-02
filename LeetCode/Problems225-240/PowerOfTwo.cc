// Title: Power of Two
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/7/2

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && ((n & (n - 1)) == 0);
	}
};

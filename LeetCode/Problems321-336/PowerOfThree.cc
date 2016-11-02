// Title: Power of Three
// Language: C++
// Runtime: 146 ms
// Submitted: 2016/7/2

class Solution {
public:
	bool isPowerOfThree(int n) {
		return (n > 0) && (1162261467 % n == 0);
	}
};

// Language: C++
// Runtime: 62 ms
// Submitted: 2016/11/2
class Solution {
public:
	bool isPowerOfThree(int n) {
		return (n > 0 && int(log10(n) / log10(3)) - log10(n) / log10(3) == 0);
	}
};

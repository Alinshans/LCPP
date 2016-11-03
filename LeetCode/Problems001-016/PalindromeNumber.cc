// Title: Palindrome Number
// Language: C++
// Runtime: 86 ms
// Submitted: 2016/11/3

class Solution {
public:
	bool isPalindrome(int x) {
		if (x<0) return false;
		int digits = 1;
		while (x / digits >= 10) digits *= 10;
		while (x) {
			int left = x / digits;
			int right = x % 10;
			if (left != right)   return false;
			x = (x % digits) / 10;
			digits /= 100;
		}
		return true;
	}
};

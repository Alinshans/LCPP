// Title: Ugly Number
// Language: C++
// Runtime: 8 ms
// Submitted: 2016/7/2

class Solution {
public:
	bool isUgly(int num) {
		if (num < 0)     return 0;
		if (num == 1)    return 1;
		while (num >= 2 && num % 2 == 0)    num /= 2;
		while (num >= 3 && num % 3 == 0)    num /= 3;
		while (num >= 5 && num % 5 == 0)    num /= 5;
		return num == 1;
	}
};

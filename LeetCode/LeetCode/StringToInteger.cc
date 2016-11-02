// Title: String to Integer
// Language: C++
// Runtime: 12 ms
// Submitted: 2016/7/12

class Solution {
public:
	int myAtoi(string str) {
		int sign = 0;
		bool neg = false;
		while (sign < str.length() && str[sign] == ' ')  sign++;
		if (str[sign] == '-' || str[sign] == '+')
		{
			if (!str[sign + 1] || str[sign + 1] == '-' || str[sign + 1] == '+')  return 0;
			neg = str[sign++] == '-';
		}
		long long ans = 0;
		for (int i = 0 + sign; i < str.length(); i++)
		{
			if (str[i] >= '0' && str[i] <= '9')    ans = ans * 10 + (str[i] - '0');
			else     return !neg ? ans : (ans * -1);
			if (!neg && ans > INT_MAX)  return INT_MAX;
			if (neg && ans * -1 < INT_MIN)   return INT_MIN;
		}
		return !neg ? ans : (ans * -1);
	}
};
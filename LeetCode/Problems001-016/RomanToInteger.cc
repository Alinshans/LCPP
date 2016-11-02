// Title: Roman to Integer
// Language: C++
// Runtime: 12 ms
// Submitted: 2016/7/12

class Solution {
public:
	int get(char ch) 
	{
		if (ch == 'I')   return 1;
		if (ch == 'V')   return 5;
		if (ch == 'X')   return 10;
		if (ch == 'L')   return 50;
		if (ch == 'C')   return 100;
		if (ch == 'D')   return 500;
		if (ch == 'M')   return 1000;
		return 0;
	}
	int romanToInt(string s) {
		int sum = 0;
		for (int i = 0; i < s.length(); i++)
		{
			sum += get(s[i]);
			if (i < s.length() - 1 && get(s[i]) < get(s[i + 1]))
				sum -= get(s[i]) * 2;
		}
		return sum;
	}
};

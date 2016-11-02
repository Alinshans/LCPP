// Title: ZigZag Conversion
// Language: C++
// Runtime: 16 ms
// Submitted: 2016/7/2

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1 || s.length() <3 || s.length() <= numRows)    return s;
		string zz;
		int gap = 2 * numRows - 2;
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i; j < s.length(); j += gap)
			{
				zz.push_back(s[j]);
				if (i != 0 && i != numRows - 1 && (j + gap - 2 * i)<s.length())
				{
					zz.push_back(s[j + gap - 2 * i]);
				}
			}
		}
		return zz;
	}
};

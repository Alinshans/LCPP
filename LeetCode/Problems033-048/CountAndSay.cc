// Title: Count and Say
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/11/10

class Solution {
public:
	string countAndSay(int n) {
		string s = "1";
		while (--n)
			s = say(s);
		return s;
	}
	string say(const string& s) {
		string str = "";
		int count, number;
		for (int i = 0; i < s.length(); i = count) {
			count = i + 1;
			number = s[i] - '0';
			if (count == s.length()) {
				str += count - i + '0';
				str += number + '0';
				return str;
			}
			while (count != s.length() && s[count] == s[count - 1])   ++count;
			str += count - i + '0';
			str += number + '0';
		}
		return str;
	}
};

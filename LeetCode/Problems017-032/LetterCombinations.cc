// Title:  Letter Combinations of a Phone Number
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/11/6

class Solution {
public:
	void doSth(vector<string>& ans, string d, const string& str, string map[], int cnt) {
		if (cnt < 1 && str != "")   ans.push_back(str);
		else {
			string tmp = map[d[0] - '0'];
			for (int i = 0; i < tmp.length(); ++i)
				doSth(ans, d.substr(1), str + tmp[i], map, cnt - 1);
		}
	}
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		if (digits.length() == 0)  return ans;
		string map[] = { "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		doSth(ans, digits, "", map, digits.length());
		return ans;
	}
};

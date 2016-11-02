// Title: Pascal's Triangle
// Language: C++
// Runtime: 0 ms
// Submitted: 2016/7/12

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<int> f = { 1 };
		vector<int> s = { 1,1 };
		vector<vector<int>> v;
		if (numRows < 1) return v;
		v.push_back(f);
		if (numRows == 1)    return v;
		v.push_back(s);
		if (numRows == 2)    return v;
		for (int i = 2; i < numRows; i++)
		{
			f.erase(f.begin(), f.end());
			f.push_back(1);
			for (int j = 1; j < i; j++)
				f.push_back(v[i - 1][j - 1] + v[i - 1][j]);
			f.push_back(1);
			v.push_back(f);
		}
		return v;
	}
};

// Title: Roman to Integer
// Language: C++
// Runtime: 56 ms
// Submitted: 2016/7/19

class Solution {
public:
	vector<vector<int>> vv;
	void find(const vector<int>& v, int l, int r, const int &t)
	{
		while (l < r)
		{
			if (v[l] + v[r] + t == 0)
			{
				vector<int> tmp = { t,v[l],v[r] };
				vv.push_back(tmp);
				while (l < r && v[l] == v[l + 1])  l++;
				while (l < r && v[r] == v[r - 1])  r--;
				l++;
				r--;
			}
			else if (v[l] + v[r] + t < 0)    l++;
			else    r--;
		}
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)     return vv;
		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])    continue;
			find(nums, i + 1, nums.size() - 1, nums[i]);
		}
		return vv;
	}
};
// Title: 4Sum
// Language: C++
// Runtime: 116 ms
// Submitted: 2016/7/19

class Solution {
public:
	vector<vector<int>> vv;
	void find(const vector<int>& v, int l, int r, const int &fir, const int &sec, const int &t)
	{
		while (l < r)
		{
			if (fir + sec + v[l] + v[r] == t)
			{
				vector<int> tmp = { fir, sec, v[l], v[r] };
				vv.push_back(tmp);
				while (l < r && v[l] == v[l + 1])  l++;
				while (l < r && v[r] == v[r - 1])  r--;
				l++;
				r--;
			}
			else if (fir + sec + v[l] + v[r]  < t)    l++;
			else    r--;
		}
	}
	void threeSum(vector<int>& nums, int start, const int &first, const int &t) {
		for (int i = start; i < nums.size() - 2; i++)
		{
			if (i > start && nums[i] == nums[i - 1])    continue;
			find(nums, i + 1, nums.size() - 1, first, nums[i], t);
		}
	}
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		if (nums.size() < 4)     return vv;
		for (int i = 0; i < nums.size() - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])    continue;
			threeSum(nums, i + 1, nums[i], target);
		}
		return vv;
	}
};

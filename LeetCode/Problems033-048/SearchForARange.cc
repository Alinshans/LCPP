// Title: Search for a Range
// Language: C++
// Runtime: 9 ms
// Submitted: 2016/11/9

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ans{ -1,-1 };
		auto it = equal_range(nums.begin(), nums.end(), target);
		if (*it.first == target) {
			ans[0] = static_cast<int>(it.first - nums.begin());
			ans[1] = static_cast<int>(it.second - nums.begin() - 1);
		}
		return ans;
	}
};

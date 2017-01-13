// Title: Search Insert Position
// Language: C++
// Runtime: 6 ms
// Submitted: 2016/11/9

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		return static_cast<int>(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
	}
};

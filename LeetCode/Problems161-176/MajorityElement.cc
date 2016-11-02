// Title: Majority Element
// Language: C++
// Runtime: 40 ms
// Submitted: 2016/7/2

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

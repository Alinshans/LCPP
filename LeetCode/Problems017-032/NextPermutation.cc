// Title: Next Permutation
// Language: C++
// Runtime: 9 ms
// Submitted: 2016/11/8

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() < 2) return;
		int i = nums.size() - 1;
		while (nums[i - 1] >= nums[i])    --i;
		if (i) {
			--i;
			int ii = nums.size() - 1;
			while (nums[ii] <= nums[i])  --ii;
			swap(nums[i], nums[ii]);
			reverse(nums.begin() + i + 1, nums.end());
		}
		else
			reverse(nums.begin(), nums.end());
	}
};

// Title: Search in Rotated Sorted Array
// Language: C++
// Runtime: 3 ms
// Submitted: 2016/11/9

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.size() == 1)    return nums[0] == target ? 0 : -1;
		for (int i = 0; i < nums.size() - 1; ) {
			int j = i + 1;
			while (nums[j - 1] < nums[j])  ++j;
			auto it = lower_bound(nums.begin() + i, nums.begin() + j, target);
			if (it != nums.begin() + j && *it == target) {
				return static_cast<int>(it - nums.begin());
			}
			i += j;
		}
		return nums[nums.size() - 1] == target ? nums.size() - 1 : -1;
	}
};

// Title: Remove Duplicates from Sorted Array
// Language: C++
// Runtime: 32 ms
// Submitted: 2016/7/2

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return nums.size();
	}
};

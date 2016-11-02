// Title: Two Sum
// Language: C++
// Runtime: 23 ms
// Submitted: 2016/11/2

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		map<int, int> idx;
		for (int i = 0; i < nums.size(); ++i) {
			if (idx.count(target - nums[i])) {
				int first = idx[target - nums[i]];
				nums.clear();
				nums.push_back(first);
				nums.push_back(i);
				break;
			}
			else {
				idx[nums[i]] = i;
			}
		}
		return nums;
	}
};

// Title: 3Sum Closest
// Language: C++
// Runtime: 9 ms
// Submitted: 2016/11/5

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		const int size = nums.size();
		int ans = nums[0] + nums[1] + nums[2];
		if (size == 3)   return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < size - 2; ++i) {
			int j = i + 1, k = size - 1;
			while (j<k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(sum - target) < abs(ans - target)) {
					if (sum == target)   return sum;
					ans = sum;
				}
				if (sum > target)
					--k;
				else
					++j;
			}
		}
		return ans;
	}
};

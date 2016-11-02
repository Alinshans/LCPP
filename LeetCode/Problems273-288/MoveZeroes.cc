// Title: Move Zeroes
// Language: C++
// Runtime: 36 ms
// Submitted: 2016/11/2

// in-place
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		const int len = nums.size();
		for (int i = 0; i < len - 1; ++i) {
			if (!nums[i]) {
				for (int j = i + 1; j < len; ++j) {
					if (nums[j]) {
						swap(nums[i], nums[j]);
						if (j == len - 1)    return;
						break;
					}
				}
			}
		}
	}
};

// not in-place
// Language: C++
// Runtime: 16 ms
// Submitted: 2016/11/2
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int idx = 0;
		const int cnt = nums.size();
		vector<int> tmp(cnt, 0);
		for (int i = 0; i < cnt; ++i) {
			if (nums[i]) tmp[idx++] = nums[i];
		}
		nums.swap(tmp);
	}
};

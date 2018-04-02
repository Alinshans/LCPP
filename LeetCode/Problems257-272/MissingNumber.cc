// Title: Missing Number
// Language: C++
// Runtime: 32 ms
// Submitted: 2018/4/1

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res = res ^ nums[i] ^ i;
        }
        return res ^= n;
    }
};

// Title: Subsets
// Language: C++
// Runtime: 10 ms
// Submitted: 2018/3/29

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int e = nums.size(), n = pow(2, nums.size());
        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < e; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((j >> i) & 1)  // Does the jth sort take the ith element
                    ans[j].push_back(nums[i]);
            }
        }
        return ans;
    }
};

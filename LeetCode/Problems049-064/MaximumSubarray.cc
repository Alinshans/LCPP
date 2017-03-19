// Title: Maximum Subarray 
// Language: C++
// Runtime: 16 ms
// Submitted: 2017/3/19

class Solution
{
public:
  int maxSubArray(vector<int>& nums)
  {
    int* dp = new int[nums.size()];
    dp[0] = nums[0];
    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      ans = max(dp[i], ans);
    }
    return ans;
  }
};

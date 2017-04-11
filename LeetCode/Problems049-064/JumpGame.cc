// Title: Jump Game  
// Language: C++
// Runtime: 12 ms
// Submitted: 2017/4/11

class Solution
{
public:
  bool canJump(vector<int>& nums)
  {
    int reach = 0;
    int size = nums.size() - 1;
    for (int i = 0; i <= size; ++i)
    {
      reach = max(reach, nums[i] + i);
      if (reach >= size || reach <= i) break;
    }
    return reach >= size;
  }
};

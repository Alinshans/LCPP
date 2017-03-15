// Title: Permutations 
// Language: C++
// Runtime: 13 ms
// Submitted: 2017/3/15

class Solution
{
public:
  vector<vector<int>> permute(vector<int>& nums)
  {
    vector<vector<int>> res;
    if (nums.size() < 2)
    {
      res.push_back(nums);
      return res;
    }
    sort(nums.begin(), nums.end());
    do
    {
      res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return res;
  }
};

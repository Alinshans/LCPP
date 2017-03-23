// Title: Group Anagrams 
// Language: C++
// Runtime: 26 ms
// Submitted: 2017/3/23

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs)
  {
    vector<vector<string>> ans;
    map<size_t, int> m;
    int k[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
    int sub = 0;
    for (auto&& s : strs)
    {
      size_t h = 1;
      for (size_t i = 0; i < s.size(); ++i)
      {
        h *= k[s[i] - 'a'];
      }
      if (m.find(h) != m.end())
      {
        ans[m[h]].emplace_back(s);
      }
      else
      {
        ans.emplace_back(vector<string>{s});
        m[h] = sub++;
      }
    }
    return ans;
  }
};

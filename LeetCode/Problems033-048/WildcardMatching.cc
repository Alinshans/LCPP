// Title: Wildcard Matching
// Language: C++
// Runtime: 39 ms
// Submitted: 2017/3/20

class Solution
{
public:
  bool isMatch(const string& s, const string& p)
  {
    if (p == "?*") return true;
    int m = s.length(), i = 0, j = 0, s1 = -1, s2 = -1;
    for (; i < m; ++i, ++j)
    {
      if (p[j] == '*')
      {
        s1 = i;
        s2 = j;
        --i;
        continue;
      }
      if (s[i] != p[j] && p[j] != '?')
      {
        if (s1 >= 0)
        {
          i = s1++;
          j = s2;
        }
        else
        {
          return false;
        }
      }
    }
    while (p[j] == '*')
      ++j;
    return j == p.length();
  }
};

// Title: Rotate Image
// Language: C++
// Runtime: 6 ms
// Submitted: 2017/3/15

class Solution
{
public:
  void rotate(vector<vector<int>>& matrix)
  {
    for (int i = matrix.size() - 1, j = 0; i > 0; i -= 2, ++j)
    {
      r(matrix, i, j);
    }
  }
  void r(vector<vector<int>>& m, int n, int c)
  {
    const auto& s = m.size() - 1;
    for (int i = c, j = 0; j < n; ++i, ++j)
    {
      auto tmp        = m[c][i];
      m[c][i]         = m[s - i][c];
      m[s - i][c]     = m[s - c][s - i];
      m[s - c][s - i] = m[i][s - c];
      m[i][s - c]     = tmp;
    }
  }
};

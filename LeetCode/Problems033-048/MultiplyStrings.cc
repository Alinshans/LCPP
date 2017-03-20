// Title: Multiply Strings 
// Language: C++
// Runtime: 9 ms
// Submitted: 2017/3/19

class Solution
{
public:
  string multiply(string num1, string num2)
  {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1 == "1") return num2;
    if (num2 == "1") return num1;
    string ans(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i)
    {
      int c = 0;
      for (int j = num2.size() - 1; j >= 0; --j)
      {
        int m = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + c;
        ans[i + j + 1] = m % 10 + '0';
        c = m / 10;
      }
      if (c)
      {
        ans[i] += c;
      }
    }
    return ans.substr(ans.find_first_not_of('0'));
  }
};

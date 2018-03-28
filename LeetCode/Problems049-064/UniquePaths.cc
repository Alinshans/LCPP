// Title: Unique Paths
// Language: C++
// Runtime: 4 ms
// Submitted: 2018/3/28

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                dp[i][j] = 1;
            }
        }
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};

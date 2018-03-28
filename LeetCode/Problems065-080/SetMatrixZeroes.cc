// Title: Set Matrix Zeroes
// Language: C++
// Runtime: 66 ms
// Submitted: 2018/3/28

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return;
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> zc;
        for (int i = 0; i < m; ++i) {
            bool z = false;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    z = true;
                    zc.push_back(j);
                }
            }
            if (z) {
                for (int j = 0; j < n; ++j) {
                    matrix[i][j] = 0;
                }   
            }
        }
        for (auto&& c : zc) {
            for (int i = 0; i < m; ++i) {
                matrix[i][c] = 0;
            }
        }
    }
};

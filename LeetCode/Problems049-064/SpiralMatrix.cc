// Title: Spiral Matrix 
// Language: C++
// Runtime: 3 ms
// Submitted: 2018/3/28

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        int m = matrix.size(), n = matrix[0].size();
        int up = 0, down = m - 1, left = 0, right = n - 1;
        std::vector<int> spiral(m * n);
        int j = 0;
        while(1) {
            for (int i = left; i <= right; ++i) spiral[j++] = matrix[up][i];
            if (++up > down) break;
            for (int i = up; i <= down; ++i) spiral[j++] = matrix[i][right];
            if (--right < left) break;
            for (int i = right; i >= left; --i) spiral[j++] = matrix[down][i];
            if (--down < up) break;
            for (int i = down; i >= up; --i) spiral[j++] = matrix[i][left];
            if (++left > right) break;
        }
        return spiral;
    }
};

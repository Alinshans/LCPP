// Title: Word Search
// Language: C++
// Runtime: 21 ms
// Submitted: 2018/3/29

class Solution {
public:
    bool exist(vector<vector<char>>& board, const string& word) {
        if (word.size() == 0) return true;
        int r = board.size();
        if (r == 0) return false;
        int c = board[0].size();
        if (c == 0) return false;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (board[i][j] == word[0] && dps(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    
    bool dps(vector<vector<char>>& b, const string& w, int i, int j, int n) {
        char c = b[i][j];
        if (c != w[n]) return false;
        if (n == w.size() - 1) return true;
        b[i][j] = '.';
        if (i != 0 && dps(b, w, i - 1, j, n + 1)) return true;
        if (i != b.size() - 1 && dps(b, w, i + 1, j, n + 1)) return true;
        if (j != 0 && dps(b, w, i, j - 1, n + 1)) return true;
        if (j != b[0].size() - 1 && dps(b, w, i, j + 1, n + 1)) return true;
        b[i][j] = c;
        return false;
    }
};

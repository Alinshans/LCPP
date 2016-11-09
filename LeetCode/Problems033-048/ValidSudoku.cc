// Title: Valid Sudoku
// Language: C++
// Runtime: 9 ms
// Submitted: 2016/11/9

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int b[9][9];
		int row[9][9];
		int col[9][9];
		memset(b, 0, sizeof(b));
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (int i = 0; i<9; ++i) {
			for (int j = 0; j <9; ++j) {
				if (board[i][j] == '.') continue;
				int v = board[i][j] - '1';
				if (++b[i / 3 * 3 + j / 3][v] > 1 || ++row[i][v] > 1 || ++col[j][v] > 1) return false;
			}
		}
		return true;
	}
};

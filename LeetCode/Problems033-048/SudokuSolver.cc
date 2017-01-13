// Title: Sudoku Solver
// Language: C++
// Runtime: 63 ms
// Submitted: 2016/11/9

class Solution {
public:
	bool dfs(vector<vector<char>>& b, int i, int j) {
		if (j == 9)  return dfs(b, i + 1, 0);
		if (i == 9)  return true;
		if (b[i][j] == '.') {
			for (int k = 0; k < 9; ++k) {
				b[i][j] = k + '1';
				if (check(b, i, j))
					if (dfs(b, i, j + 1))
						return true;
				b[i][j] = '.';
			}
		}
		else
			return dfs(b, i, j + 1);
		return false;
	}
	bool check(vector<vector<char>>& b, int i, int j) {
		for (int k = 0; k < 9; ++k)
			if ((k != j && b[i][k] == b[i][j]) || (k != i && b[k][j] == b[i][j]))  return false;
		for (int r = i / 3 * 3; r < i / 3 * 3 + 3; ++r)
			for (int c = j / 3 * 3; c < j / 3 * 3 + 3; ++c)
				if ((r != i || c != j) && b[r][c] == b[i][j])    return false;
		return true;
	}
	void solveSudoku(vector<vector<char>>& board) {
		dfs(board, 0, 0);
	}
};

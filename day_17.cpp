#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using std::vector;
using std::string;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, n, m);
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1, n, m);
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(board, 0, i, n, m);
            if (board[n - 1][i] == 'O')
                dfs(board, n - 1, i, n, m);
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'C') board[i][j] = 'O';
            }
        }
    }

    void dfs(vector<vector<char>> &board, int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;
        board[i][j] = 'C';
        dfs(board, i, j - 1, n, m);
        dfs(board, i, j + 1, n, m);
        dfs(board, i - 1, j, n, m);
        dfs(board, i + 1, j, n, m);
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    Solution solution = Solution();
    solution.solve(board);

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

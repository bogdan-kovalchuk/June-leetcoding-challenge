#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using std::vector;
using std::string;

class Solution {
public:
    void solve(vector<vector<char>> &board) {

    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};

    Solution solution = Solution();
    solution.solve(board);

    return 0;
}

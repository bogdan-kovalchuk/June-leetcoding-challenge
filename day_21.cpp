#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> d(n + 1, vector<int>(m + 1, INT32_MAX));
        d[n][m - 1] = 1;
        d[n - 1][m] = 1;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                d[i][j] = std::max(std::min(d[i + 1][j], d[i][j + 1]) - dungeon[i][j], 1);
            }

        }
        return d[0][0];
    }
};

int main() {
    vector<vector<int>> dungeon = {{-2, -3,  3},
                                   {-5, -10, 1},
                                   {10, 30,  -5}};

    Solution solution = Solution();
    std::cout << solution.calculateMinimumHP(dungeon) << std::endl;

    return 0;
}

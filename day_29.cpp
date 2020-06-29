#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::multiset;
using std::stack;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    int m = 7, n = 3;

    Solution solution = Solution();
    std::cout << solution.uniquePaths(m, n) << std::endl;

    return 0;
}


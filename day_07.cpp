#include <iostream>
#include <vector>
#include <map>


using std::vector;
using std::map;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= coins.size(); ++i) dp[i][0] = 1;

        for (int i = 1; i <= coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (j < coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp.back().back();
    }
};


int main() {
    int amount = 0;
    vector<int> coins = {};

    Solution solution = Solution();
    std::cout << solution.change(amount, coins) << std::endl;

    return 0;
}

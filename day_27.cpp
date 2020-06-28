#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp{0};

        while (dp.size() <= n) {
            int j = dp.size();
            int s = INT32_MAX;
            for (int i = 1; i * i <= j; ++i)
                s = std::min(s, dp[j - i * i] + 1);
            dp.push_back(s);
        }

        return dp[n];
    }
};

int main() {
    int n = 12;

    Solution solution = Solution();
    std::cout << solution.numSquares(n) << std::endl;

    return 0;
}


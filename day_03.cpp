#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>> &costs) {
        int result = 0;
        std::sort(costs.begin(), costs.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        for (int i = 0; i < costs.size(); ++i)
            result += i < costs.size() / 2 ? costs[i][0] : costs[i][1];

        return result;

    }
};

int main() {
    vector<vector<int>> costs = {{259, 770},
                                 {448, 54},
                                 {926, 667},
                                 {184, 139},
                                 {840, 118},
                                 {577, 469}};

    Solution solution;
    std::cout << solution.twoCitySchedCost(costs);

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


using std::vector;
using std::unordered_map;
using std::queue;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        unordered_map<int, vector<vector<int>>> g;
        int min_cost = INT_MAX;

        for (const auto &f : flights)
            g[f[0]].push_back({f[1], f[2]});

        queue<vector<int>> q;
        q.push({src, 0, -1});

        while (!q.empty()) {
            vector<int> current_city = q.front();
            q.pop();

            if (current_city[0] == dst) {
                min_cost = std::min(min_cost, current_city[1]);
                continue;
            }

            for (const auto &c : g[current_city[0]])
                if (current_city[2] + 1 <= K && current_city[1] + c[1] < min_cost)
                    q.push({c[0], current_city[1] + c[1], current_city[2] + 1});
        }

        return min_cost == INT_MAX ? -1 : min_cost;
    }
};


int main() {
    int n = 3;
    vector<vector<int>> flights = {{0, 1, 100},
                                   {1, 2, 100},
                                   {0, 2, 500}};
    int src = 0;
    int dst = 2;
    int K = 1;

    Solution solution = Solution();
    std::cout << solution.findCheapestPrice(n, flights, src, dst, K) << std::endl;

    return 0;
}

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
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        unordered_map<string, multiset<string>> g;
        vector<string> itinerary;
        if (tickets.empty()) return itinerary;

        for (auto t : tickets) g[t[0]].insert(t[1]);

        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty()) {
            string airport = dfs.top();
            if (g[airport].empty()) {
                itinerary.push_back(airport);
                dfs.pop();
            } else {
                dfs.push(*(g[airport].begin()));
                g[airport].erase(g[airport].begin());
            }
        }
        std::reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

int main() {
    vector<vector<string>> tickets = {{"MUC", "LHR"},
                                      {"JFK", "MUC"},
                                      {"SFO", "SJC"},
                                      {"LHR", "SFO"}};

    Solution solution = Solution();
    vector<string> res = solution.findItinerary(tickets);

    return 0;
}


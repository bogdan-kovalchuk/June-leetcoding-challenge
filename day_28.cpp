#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {

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


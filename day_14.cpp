#include <iostream>
#include <vector>
#include <set>


using std::vector;
using std::set;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        return 0;
    }
};


int main() {
    int n = 3;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    int src = 0;
    int dst = 2;
    int K = 1;

    Solution solution = Solution();
    std::cout << solution.findCheapestPrice(n, flights, src, dst, K) << std::endl;

    return 0;
}

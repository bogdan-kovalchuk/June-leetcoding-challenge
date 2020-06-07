#include <iostream>
#include <vector>
#include <map>


using std::vector;
using std::map;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return 0;
    }
};


int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    Solution solution = Solution();
    std::cout << solution.change(amount, coins) << std::endl;

    return 0;
}

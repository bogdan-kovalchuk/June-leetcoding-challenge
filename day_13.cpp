#include <iostream>
#include <vector>
//#include <random>
#include <set>


using std::vector;
using std::set;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        return nums;
    }
};


int main() {
    vector<int> nums = {1,2,4,8};

    Solution solution = Solution();
    auto out = solution.largestDivisibleSubset(nums);

    for (const auto &n : out)
        std::cout << n << " ";

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        unordered_map<int, int> map;
        for (const auto &n : nums) map[n]++;

        for (const auto &m : map) {
            if (m.second != 3) {
                return m.first;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    Solution solution = Solution();
    std::cout << solution.singleNumber(nums) << std::endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int s = nums[0];
        int f = nums[0];
        do {
            s = nums[s];
            f = nums[nums[f]];
        } while (s != f);

        s = nums[0];
        while (s != f) {
            s = nums[s];
            f = nums[f];
        }

        return f;
    }
};


int main() {
    vector<int> nums = {3, 1, 3, 4, 2};

    Solution solution = Solution();
    std::cout << solution.findDuplicate(nums) << std::endl;

    return 0;
}

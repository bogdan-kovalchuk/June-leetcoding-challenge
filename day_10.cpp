#include <iostream>
#include <vector>
#include <map>
#include <string>


using std::vector;
using std::map;
using std::string;

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
            if ((nums[i] == target) || (nums[i] > target)) return i;
        return nums.size();
    }
};


int main() {
    vector<int> nums = {1, 3, 5, 6, 8};
    int target = 7;

    Solution solution = Solution();
    std::cout << solution.searchInsert(nums, target) << std::endl;

    return 0;
}

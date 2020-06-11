#include <iostream>
#include <vector>
#include <map>
#include <string>


using std::vector;
using std::map;
using std::string;

class Solution {
public:
    void sortColors(vector<int> &nums) {
        int colors[3] = {};
        for (const auto &n : nums)
            colors[n]++;

        int k = 0;
        for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); ++i) {
            for (int j = 0; j < colors[i]; ++j) {
                nums[k] = i;
                k++;
            }
        }
    }
};


int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution solution = Solution();
    solution.sortColors(nums);

    for (const auto &n : nums)
        std::cout << n << " ";

    return 0;
}

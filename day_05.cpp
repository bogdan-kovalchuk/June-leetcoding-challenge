#include <iostream>
#include <vector>
#include <cmath>


using std::vector;

class Solution {
public:
    Solution(vector<int> &w) {
        for (auto i : w) {
            sum += i;
            increment_sum.push_back(sum);
        }
    }

    int pickIndex() {
        int num = rand() % sum;
        return upper_bound(increment_sum.begin(), increment_sum.end(), num) - increment_sum.begin();
    }

private:
    vector<int> increment_sum;
    int sum = 0;
};

int main() {
    vector<int> w = {1, 3};
    auto *obj = new Solution(w);
    for (int i = 0; i < 5; ++i)

        std::cout << obj->pickIndex() << " ";

    return 0;
}

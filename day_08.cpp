#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n > 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                return false;
            }
        }
        return true;
    }
};


int main() {
    int n = 218;

    Solution solution = Solution();
    std::cout << solution.isPowerOfTwo(n) << std::endl;

    return 0;
}

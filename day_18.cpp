#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    int hIndex(vector<int> &citations) {
        int len = citations.size();
        if (len == 0) return 0;
        for (int i = 0; i < len; i++) {
            if (citations[i] >= len - i) return len - i;
        }
        return 0;
    }
};

int main() {
    vector<int> citations = {0, 1, 3, 5, 6};

    Solution solution = Solution();
    std::cout << solution.hIndex(citations) << std::endl;

    return 0;
}

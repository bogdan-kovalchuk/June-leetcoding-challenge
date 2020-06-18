#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using std::vector;
using std::string;

class Solution {
public:
    int hIndex(vector<int> &citations) {

    }
};

int main() {
    vector<int> citations = {0, 1, 3, 5, 6};

    Solution solution = Solution();
    std::cout << solution.hIndex(citations) << std::endl;

    return 0;
}

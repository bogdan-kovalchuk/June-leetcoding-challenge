#include <iostream>
#include <vector>

using std::vector;
using std::string;

class Solution {
public:
    string getPermutation(int n, int k) {
        int factorials[n];

        vector<int> list;
        list.push_back(1);

        factorials[0] = 1;
        for(int i = 1; i < n; ++i){
            factorials[i] = factorials[i - 1] * i;
            list.emplace_back(i + 1);
        }

        k--;
        string sb;
        for (int i = n - 1; i >= 0; i--){
            int j = k / factorials[i];
            k -= j * factorials[i];

            sb += std::to_string(list[j]);
            list.erase(list.begin() + j);
        }
        return sb;
    }
};

int main() {
    int n = 3, k = 3;

    Solution solution = Solution();
    std::cout << solution.getPermutation(n, k) << std::endl;

    return 0;
}

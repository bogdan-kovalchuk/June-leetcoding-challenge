#include <iostream>
#include <vector>
#include <cmath>


using std::vector;

class Solution {
public:
    void reverseString(vector<char> &s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            int tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    Solution solution;
    solution.reverseString(s);

    for (const auto &ch : s)
        std::cout << ch << " ";

    return 0;
}

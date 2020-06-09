#include <iostream>
#include <vector>
#include <map>
#include <string>


using std::vector;
using std::map;
using std::string;

class Solution {
public:
    bool isSubsequence(const string &s, const string &t) {
        if (s.size() > t.size()) return false;
        if (s.empty()) return true;

        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};


int main() {
    string s = "abc", t = "ahbgdc";

    Solution solution = Solution();
    std::cout << solution.isSubsequence(s, t) << std::endl;

    return 0;
}

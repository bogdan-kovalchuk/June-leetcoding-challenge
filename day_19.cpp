#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::string;

class Solution {
public:
    string longestDupSubstring(string S) {
        unordered_map<string, int> m;
        string out;
        int max_len = 0;
        for (int i = 0; i < S.size(); i++){
            string s;
            for(int j =i; j < S.size(); j++){
                s+= S[j];
                if (s.size() >= 2){
                    m[s]++;
                    if (s.size() > max_len && m[s] >= 2){
                        max_len = s.size();
                        out = s;
                    }
                }
            }
        }
        return out;
    }
};

int main() {
    string S = "banana";

    Solution solution = Solution();
    std::cout << solution.longestDupSubstring(S) << std::endl;

    return 0;
}

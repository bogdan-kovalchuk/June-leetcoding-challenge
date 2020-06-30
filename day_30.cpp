#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::multiset;
using std::stack;

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        return words;
    }
};

int main() {
    vector<vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution solution = Solution();
    vector<string> res = solution.findWords(board, words);

    for (const auto &w : res)
        std::cout << w << std::endl;

    return 0;
}


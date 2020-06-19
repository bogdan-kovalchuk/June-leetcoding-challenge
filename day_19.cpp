#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::string;

class Solution {
public:
    string longestDupSubstring(const string &S) {
        int beg = 0, end = S.size();
        int q = INT32_MAX;
        string found;
        while (beg + 1 < end) {
            int mid = (beg + end) / 2;
            string candidate;
            if (rabinKarp(S, mid, q, candidate)) {
                beg = mid;
                found = candidate;
            } else {
                end = mid;
            }
        }
        return found;
    }

    bool rabinKarp(const string &text, int M, int q, string &str) {
        if (M == 0) return true;
        int64_t h = 1, t = 0, d = 256;

        unordered_map<int64_t, vector<int>> dic;
        for (int i = 0; i < M - 1; ++i)
            h = (h * d) % q;

        for (int i = 0; i < M; ++i) {
            t = (d * t + text[i]) % q;
        }
        dic[t].push_back(0);

        for (int i = 0; i < text.size() - M; ++i) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            dic[t].push_back(i + 1);
        }

        for (const auto &item : dic) {
            for (const auto &p:  combination(item.second)) {
                if (text.substr(p[0], p[0] + M - 1) == text.substr(p[1], p[1] + M - 1)) {
                    str = text.substr(p[0], p[0] + M - 1);
                    return true;
                }
            }

        }
        str = "";
        return false;

    }

    vector<vector<int>> combination(vector<int> v) {
        vector<vector<int>> out;
        for (int i = 0; i < v.size() - 1; ++i) {
            for (int j = i + 1; j < v.size(); j++) {
                out.push_back({v[i], v[j]});
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

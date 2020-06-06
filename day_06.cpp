#include <iostream>
#include <vector>
#include <map>


using std::vector;
using std::map;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        map<int, vector<int>, std::greater<int>> m;

        for (const auto &p : people)
            m[p[0]].emplace_back(p[1]);

        vector<vector<int>> tmp;
        for (auto &p : m) {
            std::sort(p.second.begin(), p.second.end());

            for (const auto &h : p.second){
                vector<int> pp = {p.first, h};
                tmp.emplace_back(pp);
            }
        }

        vector<vector<int>> out;
        for (const auto &p : tmp)
            out.insert(out.begin() + p[1], p);

        return out;
    }
};


int main() {
    vector<vector<int>> people = {{7, 0},
                                  {4, 4},
                                  {7, 1},
                                  {5, 0},
                                  {6, 1},
                                  {5, 2}};


    Solution solution = Solution();
    vector<vector<int>> out = solution.reconstructQueue(people);

    for (const auto &p : out)
        std::cout << p[0] << "," << p[1] << " ";

    return 0;
}

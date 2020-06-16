#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using std::vector;
using std::string;

class Solution {
public:
    string validIPAddress(string IP) {
        string part;
        int parts = 0;
        std::istringstream ss(IP);

        if (IP.find(':') != string::npos) {
            while (getline(ss, part, ':')) {
                ++parts;
                if (parts > 8 || part.empty() || part.size() > 4) return "Neither";
                for (char c : part) {
                    if (!(c >= '0' && c <= '9') && !(c >= 'a' && c <= 'f') && !(c >= 'A' && c <= 'F')) return "Neither";
                }
            }
            return (parts == 8 && IP.back() != ':') ? "IPv6" : "Neither";

        } else {
            while (getline(ss, part, '.')) {
                parts++;
                if (parts > 4 || part.empty() || (part.size() > 1 && part[0] == '0') || part.size() > 3)
                    return "Neither";

                for (char c : part)
                    if (c < '0' || c > '9') return "Neither";

                int num = stoi(part);
                if (num < 0 || num > 255) return "Neither";
            }
            return (parts == 4 && IP.back() != '.') ? "IPv4" : "Neither";
        }
    }
};

int main() {
//    string IP = "2001:0db8:85a3:0:0:8A2E:0370:7334";
    string IP = "172.16.254.01";

    Solution solution = Solution();
    std::cout << solution.validIPAddress(IP) << std::endl;

    return 0;
}

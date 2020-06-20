#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
using std::unordered_map;
using std::string;

class Solution {
    int prime = INT16_MAX;
    vector<int> power;
public:
    string longestDupSubstring(const string &S) {
        int n = S.size();
        int beg = 0, end = n - 1;
        string result;

        power = vector<int>(n, 1);
        for (int i = 1; i < n; i++)
            power[i] = (power[i - 1] * 26) % prime;

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            string candidate = rabinKarp(S, mid);

            if (candidate.size() > result.size()) {
                result = candidate;
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return result;
    }

    string rabinKarp(const string &S, int len) {
        if (len == 0) return "";
        int n = S.size(), t = 0;
        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < len; i++) {
            t = (t * 26 + (S[i] - 'a')) % prime;
        }
        hash[t] = {0};

//        for (auto p: hash) {
//            for (auto c: p.second) {
//                std::cout << c << " ";
//            }
//            std::cout << std::endl;
//        }

        for (int i = len; i < n; i++) {
            t = ((t - power[len - 1] * (S[i - len] - 'a')) % prime + prime) % prime;
            t = (t * 26 + (S[i] - 'a')) % prime;

            if (hash.find(t) == hash.end()) hash[t] = {i - len + 1};
            else {
                for (int index: hash[t]) {
                    if (S.substr(index, len) == S.substr(i - len + 1, len))
                        return S.substr(index, len);
                }
                hash[t].push_back({i - len + 1});
            }
        }
        return "";
    }
};

int main() {
    string S = "moplvidmaagmsiyyrkchbyhivlqwqsjcgtumqscmxrxrvwsnjjvygrelcbjgbpounhuyealllginkitfaiviraqcycjmskrozcdqylbuejrgfnquercvghppljmojfvylcxakyjxnampmakyjbqgwbyokaybcuklkaqzawageypfqhhasetugatdaxpvtevrigynxbqodiyioapgxqkndujeranxgebnpgsukybyowbxhgpkwjfdywfkpufcxzzqiuglkakibbkobonunnzwbjktykebfcbobxdflnyzngheatpcvnhdwkkhnlwnjdnrmjaevqopvinnzgacjkbhvsdsvuuwwhwesgtdzuctshytyfugdqswvxisyxcxoihfgzxnidnfadphwumtgdfmhjkaryjxvfquucltmuoosamjwqqzeleaiplwcbbxjxxvgsnonoivbnmiwbnijkzgoenohqncjqnckxbhpvreasdyvffrolobxzrmrbvwkpdbfvbwwyibydhndmpvqyfmqjwosclwxhgxmwjiksjvsnwupraojuatksjfqkvvfroqxsraskbdbgtppjrnzpfzabmcczlwynwomebvrihxugvjmtrkzdwuafozjcfqacenabmmxzcueyqwvbtslhjeiopgbrbvfbnpmvlnyexopoahgmwplwxnxqzhucdieyvbgtkfmdeocamzenecqlbhqmdfrvpsqyxvkkyfrbyolzvcpcbkdprttijkzcrgciidavsmrczbollxbkytqjwbiupvsorvkorfriajdtsowenhpmdtvamkoqacwwlkqfdzorjtepwlemunyrghwlvjgaxbzawmikfhtaniwviqiaeinbsqidetfsdbgsydkxgwoqyztaqmyeefaihmgrbxzyheoegawthcsyyrpyvnhysynoaikwtvmwathsomddhltxpeuxettpbeftmmyrqclnzwljlpxazrzzdosemwmthcvgwtxtinffopqxbufjwsvhqamxpydcnpekqhsovvqugqhbgweaiheeicmkdtxltkalexbeftuxvwnxmqqjeyourvbdfikqnzdipmmmiltjapovlhkpunxljeutwhenrxyfeufmzipqvergdkwptkilwzdxlydxbjoxjzxwcfmznfqgoaemrrxuwpfkftwejubxkgjlizljoynvidqwxnvhngqakmmehtvykbjwrrrjvwnrteeoxmtygiiygynedvfzwkvmffghuduspyyrnftyvsvjstfohwwyxhmlfmwguxxzgwdzwlnnltpjvnzswhmbzgdwzhvbgkiddhirgljbflgvyksxgnsvztcywpvutqryzdeerlildbzmtsgnebvsjetdnfgikrbsktbrdamfccvcptfaaklmcaqmglneebpdxkvcwwpndrjqnpqgbgihsfeotgggkdbvcdwfjanvafvxsvvhzyncwlmqqsmledzfnxxfyvcmhtjreykqlrfiqlsqzraqgtmocijejneeezqxbtomkwugapwesrinfiaxwxradnuvbyssqkznwwpsbgatlsxfhpcidfgzrc";

    Solution solution = Solution();
    std::cout << solution.longestDupSubstring(S) << std::endl;

    return 0;
}

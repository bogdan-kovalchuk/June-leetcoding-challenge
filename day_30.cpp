#include <iostream>
#include <vector>
#include <string>
#include <set>

using std::vector;
using std::string;
using std::multiset;
using std::set;

class TrieNode {
public:
    bool end;
    vector<TrieNode *> children;

    TrieNode() {
        end = false;
        children = vector<TrieNode *>(26, nullptr);
    }
};

class Trie {
public:
    TrieNode *getRoot() { return root; }

    Trie(vector<string> &words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i)
            addWord(words[i]);
    }

    void addWord(const string &word) {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (cur->children[index] == nullptr)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->end = true;
    }

private:
    TrieNode *root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        Trie *trie = new Trie(words);
        TrieNode *root = trie->getRoot();

        set<string> set;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                findWords(board, i, j, root, "", set);
            }
        }

        vector<string> result;
        for (const auto &w: set)
            result.emplace_back(w);

        return result;
    }

private:
    void findWords(vector<vector<char>> &board, int x, int y, TrieNode *root, string word, set<string> &result) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;

        if (root->children[board[x][y] - 'a'] != nullptr) {
            word = word + board[x][y];
            root = root->children[board[x][y] - 'a'];
            if (root->end) result.insert(word);
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x + 1, y, root, word, result);
            findWords(board, x - 1, y, root, word, result);
            findWords(board, x, y + 1, root, word, result);
            findWords(board, x, y - 1, root, word, result);
            board[x][y] = c;
        }
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


#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        int n = 1;
        if (root->left != nullptr) {
            n += countNodes(root->left);
        }
        if (root->right != nullptr) {
            n += countNodes(root->right);
        }
        return n;
    }
};

TreeNode *insertLevelOrder(vector<int> nodes, TreeNode *root, int i, int n) {
    // Base case for recursion
    if (i < n && nodes[i] != 0) {
        auto *temp = new TreeNode(nodes[i]);
        root = temp;

        // insert left child
        root->left = insertLevelOrder(nodes, root->left, 2 * i + 1, n);

        // insert right child
        root->right = insertLevelOrder(nodes, root->right, 2 * i + 2, n);
    }
    return root;
}


int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, 6};

    TreeNode *root = insertLevelOrder(nodes, root, 0, nodes.size());

    Solution solution = Solution();
    std::cout << solution.countNodes(root) << std::endl;

    return 0;
}

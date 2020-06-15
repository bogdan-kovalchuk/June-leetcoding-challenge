#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


using std::vector;
using std::unordered_map;
using std::queue;

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
    TreeNode *searchBST(TreeNode *root, int val) {
        bool out_flag = false;
        return travers(root, val, out_flag);
    }

    TreeNode *travers(TreeNode *root, int val, bool &out_flag) {
        if (root == nullptr || out_flag) return nullptr;

        if (root->val == val) {
            out_flag = true;
            return root;
        }

        TreeNode *left = travers(root->left, val, out_flag);
        TreeNode *right = travers(root->right, val, out_flag);

        if (left != nullptr) return left;
        if (right != nullptr) return right;
        return nullptr;
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
    int val = 2;
    vector<int> nodes = {4, 2, 7, 1, 3};

    TreeNode *root = insertLevelOrder(nodes, root, 0, nodes.size());

    Solution solution = Solution();
    auto out = solution.searchBST(root, val);

    return 0;
}

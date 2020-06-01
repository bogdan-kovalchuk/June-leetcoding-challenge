#include <iostream>
#include <vector>

using std::vector;

//Definition for a binary tree node.
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
    TreeNode *invertTree(TreeNode *root) {
        traverce(root);
        return root;
    }

    void traverce(TreeNode *root) {
        if (root == nullptr) return;

        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        traverce(root->right);
        traverce(root->left);
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
    vector<int> nodes = {4, 2, 7, 1, 3, 6, 9};

    TreeNode *root = insertLevelOrder(nodes, root, 0, nodes.size());

    Solution solution = Solution();
    TreeNode *out = solution.invertTree(root);

    return 0;
}

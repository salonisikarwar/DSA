/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        using NodeWithIndex = pair<TreeNode*, size_t>; // size_t is safe and efficient
        queue<NodeWithIndex> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            size_t minIndex = q.front().second;  // Base index for normalization
            size_t first = 0, last = 0;

            for (int i = 0; i < levelSize; ++i) {
                auto [node, index] = q.front();
                q.pop();
                index -= minIndex;  // Normalize

                if (i == 0) first = index;
                if (i == levelSize - 1) last = index;

                if (node->left) {
                    q.push({node->left, index * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, index * 2 + 2});
                }
            }

            maxWidth = max(maxWidth, static_cast<int>(last - first + 1));
        }

        return maxWidth;
    }
};

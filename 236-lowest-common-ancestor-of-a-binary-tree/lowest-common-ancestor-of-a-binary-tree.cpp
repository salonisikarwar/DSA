/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* x) {
        if (root == NULL)
            return false;

        path.push_back(root);

        if (root == x)
            return true;

        if (getPath(root->left, path, x) || getPath(root->right, path, x))
            return true;

        path.pop_back(); // backtrack
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1, path2;

        if (!getPath(root, path1, p) || !getPath(root, path2, q))
            return NULL; // one of the nodes not present

        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }

        return path1[i - 1]; // last common ancestor
    }
};

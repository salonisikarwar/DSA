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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;

        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, inMap);
    }

    TreeNode* build(vector<int>& inorder, int istart, int iend,
                    vector<int>& postorder, int pstart, int pend,
                    map<int, int>& inMap) {

        if (pstart > pend || istart > iend) return NULL;

        TreeNode* root = new TreeNode(postorder[pend]);
        int inRoot = inMap[postorder[pend]];
        int numleft = inRoot - istart;

        root->left = build(inorder, istart, inRoot - 1,
                           postorder, pstart, pstart + numleft - 1, inMap);
        root->right = build(inorder, inRoot + 1, iend,
                            postorder, pstart + numleft, pend - 1, inMap);

        return root;
    }
};

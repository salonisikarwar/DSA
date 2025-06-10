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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result; // Return empty vector for null root
        
        // Use a helper function or direct recursion
        inorderHelper(root, result);
        return result;
    }
    
private:
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        inorderHelper(node->left, result);
        result.push_back(node->val);  // Traverse left subtree
        inorderHelper(node->right, result); // Traverse right subtree
    }
};
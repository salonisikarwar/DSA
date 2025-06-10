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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result; // Return empty vector for null root
        
        // Use a helper function or direct recursion
        preorderHelper(root, result);
        return result;
    }
    
private:
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        
        result.push_back(node->val);         // Visit root
        preorderHelper(node->left, result);  // Traverse left subtree
        preorderHelper(node->right, result); // Traverse right subtree
    }
};
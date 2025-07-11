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
 class BSTIterator {
    stack<TreeNode*> myStack;
    bool reverse; // false = normal in-order, true = reverse in-order

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        return tmpNode->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            myStack.push(node);
            if (reverse)
                node = node->right;  // Reverse in-order
            else
                node = node->left;   // Normal in-order
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
       BSTIterator l(root,false);
       BSTIterator r(root , true);
//next
       int i  = l.next();

//before
       int j = r.next();
       while(i<j)
       {
        if(i +j == k)return true;
        else if(i+j < k )i  = l.next();
        else j = r.next();
       }
       return false;

    }
};
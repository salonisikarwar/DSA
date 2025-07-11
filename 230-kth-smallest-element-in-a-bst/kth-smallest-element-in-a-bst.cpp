class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;
        int cnt = 0;
        int ans = -1;

        while (curr != NULL) {
            if (curr->left == NULL) {
                cnt++;
                if (cnt == k) ans = curr->val;
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                if (prev->right == NULL) {
                    prev->right = curr;  // Thread created
                    curr = curr->left;
                } else {
                    prev->right = NULL;  // Thread removed
                    cnt++;
                    if (cnt == k) ans = curr->val;
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};

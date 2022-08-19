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
    int maxPathSum(TreeNode* root) {
        int ans = -1000;
        (void)path(root, ans);
        return ans;
    }
private:
    int path(TreeNode* root, int& ans){
        if(root == nullptr) return 0;
        int l = max(0, path(root->left, ans));
        int r = max(0, path(root->right, ans));
        int sum = l + r + root->val;
        if(sum > ans) ans = sum;
        return max(l, r) + root->val;
    }
};
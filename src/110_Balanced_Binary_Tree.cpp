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
    bool flag = true;
    bool isBalanced(TreeNode* root) {
        if(!root) return flag;
        findH(root);
        return flag;
    }
    int findH(TreeNode* root){
        if(!root) return -1;
        int left = findH(root->left);
        int right = findH(root->right);
        if(abs(left - right) > 1) flag = false;
        return max(left, right) + 1;
    }
};
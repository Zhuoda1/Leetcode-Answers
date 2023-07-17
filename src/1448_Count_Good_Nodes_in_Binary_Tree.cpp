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
    void dfs(TreeNode* root, int& ans, int path){
        if(root->val >= path){
            ans += 1;
            path = root->val;
        }
        if(root->left) dfs(root->left, ans, path);
        if(root->right) dfs(root->right, ans, path);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        dfs(root, ans, -100005);
        return ans;
    }
};
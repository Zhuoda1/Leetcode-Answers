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
    unordered_map<int,int> ans,l,r;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        if(!root) return vector<int>();
        dfs(root);
        search(root->left,r[root->val],1);
        search(root->right,l[root->val],1);

        vector<int> res;
        for(int query : queries){
            res.push_back(ans[query]);
        }
        return res;
    }
    void search(TreeNode* root, int maximum, int h){
        if(!root) return;
        ans[root->val] = maximum;
        search(root->left,max(maximum, h+r[root->val]), h+1);
        search(root->right,max(maximum, h+l[root->val]), h+1);
    }
    int dfs(TreeNode* root){
        if(!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        l[root->val] = left;
        r[root->val] = right;
        return max(left,right) + 1;
    }
};
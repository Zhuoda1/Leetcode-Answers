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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while(q.size()){
            int len = q.size();
            long long left = q.front().second, right = q.back().second;
            ans = max(ans, right - left + 1);
            for(int i = 0; i < len; i++){
                auto [cur, pos] = q.front();
                long long idx = pos - left;
                q.pop();
                if(cur->left) q.push({cur->left, (long long)2 * idx + 1});
                if(cur->right) q.push({cur->right, (long long) 2 * idx + 2});
            }
        }
        return ans;
    }
};
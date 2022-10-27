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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        int cnt = 0;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while(!cur.empty()){
            vector<int> temp;
            for(TreeNode* node : cur){
                temp.push_back(node->val);
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            if(cnt % 2 != 0) reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            cur.swap(next);
            next.clear();
            cnt++;
        }
        return ans;
    }
};
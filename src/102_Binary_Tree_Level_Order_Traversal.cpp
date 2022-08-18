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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        vector<TreeNode*> cur, next;
        cur.push_back(root);
        while(!cur.empty()){
            ans.push_back({});
            for(TreeNode* node : cur){
                ans.back().push_back(node->val);
                if(node->left != nullptr) next.push_back(node->left);
                if(node->right != nullptr) next.push_back(node->right);
            }
            cur.swap(next);
            next.clear();
        }
        return ans;
    }

};
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
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        int num = 0;
        vector<TreeNode*> q;
        q.push_back(root);
        while(num < q.size() && q[num]){
            q.push_back(q[num]->left);
            q.push_back(q[num]->right);
            num++;
        }
        while (num < q.size()) if(q[num++]) return false;
        return true;
    }
};
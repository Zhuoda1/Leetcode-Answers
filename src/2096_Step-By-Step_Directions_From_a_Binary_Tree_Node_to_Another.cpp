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
    TreeNode* lca(TreeNode* root, int s, int e){
        if(!root) return root;
        if(root->val == s || root->val == e) return root;
        TreeNode* left = lca(root->left, s, e);
        TreeNode* right = lca(root->right, s, e);

        if(left && right) return root;
        return left ? left : right;
    }
    bool traverse(TreeNode* root, int val, string& path){
        if(!root) return false;
        if(root->val == val) return true;

        path.push_back('L');
        if(traverse(root->left, val, path)) return true;
        path.pop_back();

        path.push_back('R');
        if(traverse(root->right, val, path)) return true;
        path.pop_back();   

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ancestor = lca(root, startValue, destValue);
        string start;
        string end;
        traverse(ancestor, startValue, start);
        traverse(ancestor, destValue, end);

        for(auto& c : start) c = 'U';
        return start + end;
    }
};
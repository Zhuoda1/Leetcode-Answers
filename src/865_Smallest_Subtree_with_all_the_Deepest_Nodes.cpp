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
    int depth(TreeNode* root){
        if(!root) return -1;
        int left = depth(root->left);
        int right = depth(root->right);
        return max(left, right) + 1;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
                if(!root) return root;

        int left = depth(root->left);
        int right = depth(root->right);

        if(left == right) return root;
        else if(left < right) return subtreeWithAllDeepest(root->right);
        else return subtreeWithAllDeepest(root->left);
    }
};
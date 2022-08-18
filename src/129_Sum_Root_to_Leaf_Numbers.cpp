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
    int sumNumbers(TreeNode* root) {
        int ans=0;
        transversal(root, 0, &ans);
        return ans;
    }
private:
    void transversal(TreeNode* root, int sum, int* ans){
        if(root == nullptr) return;
        sum = sum*10 + root->val;
        if(root->left != nullptr || root->right != nullptr){
            transversal(root->left, sum, ans);
            transversal(root->right, sum, ans);
        } else{
            *ans += sum;
        }
    }
};
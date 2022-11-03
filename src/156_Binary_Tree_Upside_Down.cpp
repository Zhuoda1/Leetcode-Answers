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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        TreeNode* next = nullptr;
        TreeNode* temp = nullptr;

        while(curr){
            next = curr->left;
            curr->left = temp;
            temp = curr->right;
            curr->right = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root->left) return root;

        TreeNode* newNode = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr;
        root->right = nullptr;

        return newNode;
    }
};
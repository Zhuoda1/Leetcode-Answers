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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        stack<TreeNode*> st;

        while(!st.empty() || root != nullptr){
            while(root != nullptr){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();

            if(prev != nullptr && root->val <= prev->val) return false;

            prev = root;
            root = root->right;
        }
        return true;
    }
};
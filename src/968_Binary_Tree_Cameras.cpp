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
    int minCameraCover(TreeNode* root) {
        int cnt = 0;
        int ans = camera(root, cnt);
        if(ans == 0) return cnt+1;
        return cnt;
    }
private:
    int camera(TreeNode* root, int& cnt){
        if(root == nullptr) return -1;
        if(root->left == nullptr && root->right == nullptr) return 0;
        int l = camera(root->left, cnt);
        int r = camera(root->right, cnt);
        if(l == 0 || r == 0){
            cnt++;
            return 2;
        }
        else if(l == 2 || r == 2){
            return 1;
        }
        return 0;
    }
};
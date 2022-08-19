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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        int maxFreq = -1;
        unordered_map<int,int> map;
        (void)find(root, ans, map, maxFreq);
        return ans;
    }
private:
    int find(TreeNode* root, vector<int>& ans, unordered_map<int,int>& map, int& maxFreq){
        if(root == nullptr) return 0;
        int curr = find(root->left, ans, map, maxFreq)+find(root->right, ans, map, maxFreq)+root->val;
        int freq = ++map[curr];
        if(freq > maxFreq){
            ans.clear();
            ans.push_back(curr);
            maxFreq = freq;
        }
        else if(freq == maxFreq){
            ans.push_back(curr);
        }
        return curr;
    }
};
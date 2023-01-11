class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
    void dfs(int k, int n, int start){
        if(n == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }
        else if(n < 0 || curr.size() > k) return;
        for(int i = start; i <= 9; i++){
            curr.push_back(i);
            dfs(k, n - i, i + 1);
            curr.pop_back();
        }
    }
};
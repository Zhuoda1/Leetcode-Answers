class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    //unordered_map<int,vector<vector<int>>> m;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int start){
        if(target == 0) ans.push_back(p);

        else if(target < 0) return;

        for(int i = start; i < candidates.size(); i++){
            p.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i);
            p.pop_back();
        }
    }
};
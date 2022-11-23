class Solution {
public:
    vector<vector<int>> ans;
    vector<int> p;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0);
        return ans;
    }
    void dfs(vector<int>& candidates, int target, int start){
        if(target == 0) ans.push_back(p);

        else if(target < 0) return;

        for(int i = start; i < candidates.size(); i++){
            if(i != start && candidates[i] == candidates[i-1]) continue;
            p.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1);
            p.pop_back();
        }
    }
};
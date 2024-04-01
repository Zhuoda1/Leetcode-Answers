class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for(const auto ts : transactions){
            mp[ts[0]] -= ts[2];
            mp[ts[1]] += ts[2];
        }

        vector<int> debts;
        for(const auto& ele : mp) if(ele.second) debts.push_back(ele.second);

        return dfs(0, debts);
    }

    int dfs(int idx, vector<int>& debts){
        int res = INT_MAX;
        int n = debts.size();
        while(idx < n && !debts[idx]) idx++;
        for(int i = idx + 1; i < n; i++){
            if(debts[i] * debts[idx] < 0){
                debts[i] += debts[idx];
                res = min(res, 1 + dfs(idx + 1, debts));
                debts[i] -= debts[idx];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
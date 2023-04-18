class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> mp;
        unordered_map<string, int> need;
        unordered_set<string> s;
        for(string sup : supplies) s.insert(sup);
        int indegSize = ingredients.size();
        for(string rec : recipes) need[rec] = 0;
        for(int i = 0; i < indegSize; i++){
            for(string sup : ingredients[i]){
                if(s.count(sup) == 0){
                    mp[sup].push_back(recipes[i]);
                    need[recipes[i]]++;
                }
            }
        }
        queue<string> q;
        for(auto ele : need) {
            if(ele.second == 0) q.push(ele.first);
        }
        vector<string> ans;
        while(q.size()){
            string cur = q.front();
            q.pop();
            ans.push_back(cur);
            for(auto next : mp[cur]){
                if(--need[next] == 0) q.push(next);
            }
        }
        return ans;
    }
};
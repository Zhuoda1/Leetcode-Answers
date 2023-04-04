class Solution {
public:
    string find(string email, unordered_map<string, string>& mp){
        return mp[email] == email ? email : find(mp[email], mp);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> parent;
        unordered_map<string, string> owner;
        unordered_map<string, set<string>> uni;

        for(int i = 0; i < accounts.size(); i++){
            for(int j = 1; j < accounts[i].size(); j++){
                owner[accounts[i][j]] = accounts[i][0];
                parent[accounts[i][j]] = accounts[i][j];
            }
        }

        //union
        for(int i = 0; i < accounts.size(); i++){
            string p = find(accounts[i][1], parent);
            for(int j = 1; j < accounts[i].size(); j++){
                parent[find(accounts[i][j], parent)] = p;
            }
        }

        for(int i = 0; i < accounts.size(); i++)
            for(int j = 1; j < accounts[i].size(); j++)
                uni[find(accounts[i][j], parent)].insert(accounts[i][j]);
        
        vector<vector<string>> ans;
        for(auto ele : uni){
            vector<string> temp(ele.second.begin(), ele.second.end());
            temp.insert(temp.begin(), owner[ele.first]);
            ans.push_back(temp);
        }
        return ans;
    }
};
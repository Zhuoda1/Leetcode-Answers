class Solution {
private:
    unordered_map<int, vector<string>> ans;
    unordered_set<string> wordSet;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set(wordDict.begin(),wordDict.end());
        dfs(s,0);
        return ans[0];
    }
    void dfs(string& s, int index){
        if(!ans.count(index)){
            if(index == s.length()){
                ans[index] = {""};
                return;
            }
            ans[index] = {};
            for(int i = index + 1; i <= s.length(); i++){
                string word = s.substr(index, i - index);
                if(wordSet.count(word)){
                    dfs(s,i);
                    for(auto succ : ans[i]){
                        ans[index].push_back(succ.empty() ? word : word + " " + succ);
                    }
                }
            }
        }
    }
};
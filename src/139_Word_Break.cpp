class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        unordered_set<string> dict(wordDict.size());
        for(auto word : wordDict){
            dict.insert(word);
        }
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        vector<vector<bool>> dp(p_size + 1, vector<bool>(s_size + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= p_size; i++){
            if(p[i-1] == '*' && dp[i-2][0]) dp[i][0] = true;
        }
        for(int i = 1; i <= p_size; i++){
            for(int j = 1; j <= s_size; j++){
                if(p[i-1] == '.' || p[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[i-1] == '*'){
                    if(p[i-2] != s[j-1] && p[i-2] != '.') dp[i][j] = dp[i-2][j];
                    else dp[i][j] = (dp[i-1][j] || dp[i][j-1] || dp[i-2][j]);
                }
            }
        }
        return dp[p_size][s_size];
    }
};
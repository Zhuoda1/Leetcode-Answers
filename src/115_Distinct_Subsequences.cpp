class Solution {
public:
    int numDistinct(string s, string t) {
        int s1 = s.size();
        int s2 = t.size();
        if(s1 < s2) return 0;
        if(s1 == s2) return s == t;
        vector<vector<long>> dp(s1+1, vector<long>(s2+1, 0));
        // dp[i][j] represent number of substring of s before i form t[0,j]
        for(int i = 0; i <= s1; i++) dp[i][0] = 1;
        for(int i = 1; i <= s1; i++){
            for(int j = 1; j <= s2; j++){
                int prev = 0;
                if(s[i-1] == t[j-1]) prev = dp[i-1][j-1];
                dp[i][j] = prev + dp[i-1][j];
            }
        }
        return dp[s1][s2];
    }
};
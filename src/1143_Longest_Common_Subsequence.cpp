class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for(int i = 1; i <= len1; i++){
            char a = text1.at(i-1);
            for(int j = 1; j <= len2; j++){
                char b = text2.at(j-1);
                if(a == b){
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }

            }
        }
        return dp[len1][len2];
    }
};
class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect;
        for(int i = 1; i <= 10000; i++){
            int temp = i * i;
            if(temp > n) break;
            perfect.push_back(temp);
        }
        int len = perfect.size();
        vector<int> dp(n + 1, 10001);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < len; j++){
                if(perfect[j] > i) break;
                dp[i] = min(dp[i], dp[i-perfect[j]] + 1);
            }
        }
        return dp[n];
    }
};
class Solution {
public:
    int n;
    int dp[301][301];
    int solve(vector<int>& balloon, int i, int j){
        if(i > j) return 0;
        if(i == j){
            int temp = balloon[i];
            if(i >= 1) temp *= balloon[i-1];
            if(i < n - 1) temp *= balloon[i+1];
            return temp;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        for(int k = i; k <= j; k++){
            int temp = balloon[k];
            if(i >= 1) temp *= balloon[i-1];
            if(j < n - 1) temp *= balloon[j+1];

            ans = max(ans, temp + solve(balloon, i, k - 1) + solve(balloon, k + 1, j));
        }
        dp[i][j] = ans;
        return ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        vector<int> balloon;
        n = nums.size() + 2;
        balloon.push_back(1);
        for(int num : nums) balloon.push_back(num);
        balloon.push_back(1);
        return solve(balloon, 1, n - 2);
    }
};
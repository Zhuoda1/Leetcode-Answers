class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        return abs(sum) < abs(s) || (s + sum) & 1 ? 0 : subsetSum(nums, (s + sum) >> 1); 
    }   
    int subsetSum(vector<int>& nums, int s) {

        vector<int> dp(s +97. Interleaving String 1, 0);
        dp[0] = 1;
        for (int n : nums)
            for (int i = s; i >= n; i--)
                dp[i] += dp[i - n];
        return dp[s];
    }
};
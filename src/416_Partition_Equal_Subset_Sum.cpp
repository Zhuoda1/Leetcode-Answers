class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int partSum = 0;
        for(int num : nums) partSum += num;
        if(partSum & 1) return false;
        partSum /= 2;
        vector<bool> dp(partSum+1,0);
        dp[0] = true;
        for(int num : nums){
            for(auto i = partSum; i >= 0; i--){
                if(dp[i] && i + num <= partSum) dp[i + num] = true;
            }
        }
        return dp[partSum];
    }
};
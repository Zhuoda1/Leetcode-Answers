class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = max(nums[i], nums[i] + sum);
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};
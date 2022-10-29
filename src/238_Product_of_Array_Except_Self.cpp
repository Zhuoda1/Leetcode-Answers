class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffix = 1;
        vector<int> ans(nums.size(),1);
        for(int i = 1; i < nums.size(); i++){
            ans[i] = ans[i-1] * nums[i-1];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            ans[i] *= suffix;
            suffix *= nums[i];
        }
        return ans;
    }
};
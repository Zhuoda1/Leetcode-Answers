class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        for(int i = 0; i < n; i++) if(i > 0) pre[i] = pre[i-1] * nums[i-1];
        int suf = 1;
        for(int i = n - 1; i >= 0; i--) if(i < n){
            pre[i] *= suf;
            suf *= nums[i];
        }
        return pre;
    }
};
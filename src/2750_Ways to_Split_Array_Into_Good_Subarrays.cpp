class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        bool first = false;
        long ans = 1;
        long cur = 0;
        long mod = 1e9 + 7;
        for(int num : nums){
            if(num == 0 && first) cur++;
            else if(num == 1){
                first = true;
                ans = (ans * (cur + 1) % mod) % mod;
                cur = 0;
            }
        }
        if(!first) return 0;
        return ans % mod;
    }
};
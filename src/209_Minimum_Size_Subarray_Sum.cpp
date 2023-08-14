class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        int l = 0, r = 0, n = nums.size();
        while(r < n){
            while(r < n && sum < k) sum += nums[r++];
            while(l < r && sum >= k){
                ans = min(ans, r - l);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;       
    }
};
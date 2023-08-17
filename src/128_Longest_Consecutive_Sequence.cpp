class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int ans = 1, cur = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] != nums[i]){
                if(nums[i-1] == nums[i] - 1) cur += 1;
                else{
                    ans = max(ans, cur);
                    cur = 1;
                }
            }
        }
        return max(ans, cur);
    }
};

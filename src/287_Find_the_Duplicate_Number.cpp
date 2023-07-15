class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> cnt(nums.size(),0);
        for(auto num : nums){
            if(cnt[num]) return cnt[num];
            cnt[num] = num;
        }
        return -1;
    }
};
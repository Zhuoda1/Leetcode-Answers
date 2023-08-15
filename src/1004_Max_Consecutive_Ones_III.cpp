class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int n = nums.size(), ans = 0;
        while(right < n){
            if(nums[right] == 0) k--;
            while(left <= right && k < 0){
                if(nums[left] == 0) k++;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, cnt = 0;
        int ans = 0, len = nums.size();
        for(int right = 0; right < len; right++){
            if(nums[right] & 1){
                k--;
                cnt = 0;
            }
            while(k == 0){
                k += nums[left++] & 1;
                cnt++; 
            }
            ans += cnt;
        }
        return ans;
    }
    /*
        k = 2
        1 2 3 4 5
        l     r
    */
};
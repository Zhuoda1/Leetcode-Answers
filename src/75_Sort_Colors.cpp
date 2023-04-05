class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero=0, one=0, two=0, i;
        for(i=0; i<nums.size(); i++){
            if(!nums[i]) zero++;
            else if(nums[i]==1) one++;
            else two++;
        }
        i = 0;      
        while(zero--) nums[i++] = 0;
        while(one--) nums[i++] = 1;
        while(two--) nums[i++] = 2;
    }
};
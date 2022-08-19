class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums.front();
        int count = 0;
        for(auto x:nums){
            if(x == maj) count++;
            else if(--count == 0){
                count = 1;
                maj = x;
            }
        }
        return maj;
    }
};
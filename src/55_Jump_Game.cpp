class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for(int i = 0; i < nums.size(); i++){
            if(m < i) return false;
            m = max(i + nums[i], m);
        }
        return true;
    }
};
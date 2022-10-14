class Solution {
public:
    int jump(vector<int>& nums) {
        int m = 0, len = nums.size(), temp = 0, step = 0;
        for(int i = 0; i < len - 1; i++){
            if(m >= i){
                m = max(m, i + nums[i]);
                if(i == temp){
                    temp = m;
                    step++;
                }
            }
        }
        return step;
    }
};
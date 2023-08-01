class Solution {
public:
    int jump(vector<int>& nums) {
        int curEnd = 0, curFar = 0, step = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            curFar = max(curFar, i + nums[i]);
            if(i == curEnd){
                step++;
                curEnd = curFar;
            }
        }
        return step;
    }
};
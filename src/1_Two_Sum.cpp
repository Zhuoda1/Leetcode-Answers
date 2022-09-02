class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ans;
        vector<int> ret(2,-1);
        for(int i=0; i < nums.size(); i++){
            if(ans.count(target-nums[i]) > 0){
                ret[0] = ans[target-nums[i]];
                ret[1] = i;
                return ret;
            }
            ans[nums[i]] = i;
        }
        return ret;
    }
};
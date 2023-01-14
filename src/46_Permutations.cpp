class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }

    void backtrack(vector<int>& nums, int start){
        if(start == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[i],nums[start]);
            backtrack(nums, start + 1);
            swap(nums[i],nums[start]);
        }
    }
};
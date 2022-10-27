class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        bt(0, nums, ans, vector<int>());
        return ans;
    }
    void bt(int index, vector<int>& nums, vector<vector<int>>& ans, vector<int> temp){
        ans.push_back(temp);
        for(int j = index; j < nums.size(); j++){
            temp.push_back(nums[j]);
            bt(j+1, nums, ans, temp);
            temp.pop_back();
        }
    }
};
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0, r = 0;
        vector<string> ans;
        string temp = "";
        while(r < nums.size()){
            while(r < nums.size() - 1 && nums[r] + 1== nums[r + 1]){
                r++;
            }
            temp = to_string(nums[l]);
            if(l != r){
                temp.append("->");
                temp.append(to_string(nums[r]));
            }
            l = ++r;
            ans.push_back(temp);
        }
        return ans;
    }
};
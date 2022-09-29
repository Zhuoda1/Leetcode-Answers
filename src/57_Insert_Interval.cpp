class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        vector<vector<int>> ans;
        bool placed = false;
        for(auto interval : intervals){
            if(interval[0] > right){
                if(!placed){
                    ans.push_back({left,right});
                    placed = true;
                }
                ans.push_back(interval);
            }
            else if(interval[1] < left){
                ans.push_back(interval);
            }
            else{
                left = min(interval[0], left);
                right = max(interval[1], right);
            }
        }
        if(!placed){
            ans.push_back({left,right});
        }
        return ans;
    }
};
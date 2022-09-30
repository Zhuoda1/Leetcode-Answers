class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> win;

        for(int i = 0; i < k; i++){
            win.emplace(nums[i],i);
        }

        vector<int> ans;
        ans.push_back(win.top().first);
        for(int i = k; i < nums.size(); i++){
            win.emplace(nums[i],i);
            while(win.top().second <= i - k){
                win.pop();
            }
            ans.push_back(win.top().first);
        }
        return ans;
    }
};
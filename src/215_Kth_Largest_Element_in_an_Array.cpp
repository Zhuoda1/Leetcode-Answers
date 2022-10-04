class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> h;
        for(int i = 0; i < nums.size(); i++){
            h.push(nums[i]);
        }
        int ans;
        for(int i = 0; i < k; i++){
            ans = h.top();
            h.pop();
        }
        return ans;
    }
};
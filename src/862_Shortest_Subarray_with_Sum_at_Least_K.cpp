class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> B(n, 0);
        B[0] = nums[0];
        deque<int> d;
        int ans = n + 1;
        for(int i = 0; i < n; i++){
            if(i > 0) B[i] = nums[i] + B[i-1];
            if(B[i] >= k) ans = min(ans, i + 1);
            while(d.size() && B[i] - B[d.front()] >= k){
                ans = min(ans, i - d.front());
                d.pop_front();
            }
            while(d.size() && B[i] <= B[d.back()]) d.pop_back();
            d.push_back(i);
        }
        return ans <= n ? ans : -1;
    }
};
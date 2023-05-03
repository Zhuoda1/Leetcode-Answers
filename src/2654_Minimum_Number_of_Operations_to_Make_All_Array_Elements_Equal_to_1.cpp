class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = count(nums.begin(), nums.end(), 1);
        if(cnt) return n - cnt;
        int op = INT_MAX;
        for(int i = 0; i < n; i++){
            int p = nums[i];
            for(int j = i + 1; j < n; j++){
                p = __gcd(p, nums[j]);
                if(p == 1) op = min(op, j - i + n - 1);
            }
        }
        return (op == INT_MAX ? -1 : op);
    }
};
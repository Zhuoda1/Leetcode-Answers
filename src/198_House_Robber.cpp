class Solution {
public:
    int rob(vector<int>& nums) {
        // steal from prev or steal from curr
        int pre = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
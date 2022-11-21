class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m = {{0,1}};
        int cnt = 0, sum = 0;
        for(auto num : nums){
            sum += num;
            if(m.count(sum-k)) cnt += m[sum-k];
            m[sum] += 1;
        }
        return cnt;
    }
};
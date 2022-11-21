class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m = {{0,1}};
        int cnt = 0, sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int mod = (sum % k + k) % k;
            if(m.count(mod)) cnt += m[mod];
            m[mod] += 1;
        }
        return cnt;
    }
};
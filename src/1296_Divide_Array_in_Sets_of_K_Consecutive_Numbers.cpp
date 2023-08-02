class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;

        map<int, int> mp;
        for(const auto& num : nums) mp[num] += 1;

        while(mp.size()){
            int cur = mp.begin()->first;
            for(int i = 0; i < k; i++){
                if(mp[cur + i] == 0) return false;
                else if(--mp[cur + i] == 0) mp.erase(cur + i);
            }
        }
        return true;
    }
};
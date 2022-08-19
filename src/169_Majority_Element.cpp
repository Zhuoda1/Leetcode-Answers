class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int max = 0;
        int length = nums.size();
        for(auto x:nums){
            if(++map[x] > length/2) return x;
        }
        return -1;
    }
};
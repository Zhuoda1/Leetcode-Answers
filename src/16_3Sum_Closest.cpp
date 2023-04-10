class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int ans;
        for(int i = 0; i < nums.size(); i++){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return sum;
                int dis = sum - target > 0 ? sum - target : target - sum;
                if(dis < closest){
                    closest = dis;
                    ans = sum;
                }
                if(sum > target) right--;
                else left++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int arr[101] = {};
        vector<int> ans;
        for(int i = 0; i < k; i++) arr[nums[i] + 50] += 1;
        int temp = 0;
        for(int p = 0; p <= 100; p++){
            temp += arr[p];
            if(temp >= x){
                ans.push_back(min(p - 50, 0));
                break;
            }
        }
        for(int i = k; i < nums.size(); i++){
            arr[nums[i-k] + 50] -= 1;
            arr[nums[i] + 50] += 1;
            temp = 0;
            for(int p = 0; p <= 100; p++){
                temp += arr[p];
                if(temp >= x){
                    ans.push_back(min(p - 50, 0));
                    break;
                }
            }
        }
        return ans;
    }
};
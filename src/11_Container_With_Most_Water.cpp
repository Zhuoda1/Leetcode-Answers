class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ans = 0;
        while(left < right){
            ans = (height[left] < height[right]) ? max(ans, (right - left) * height[left++]) : max(ans, (right - left) * height[right--]);
        }
        return ans;
    }
};
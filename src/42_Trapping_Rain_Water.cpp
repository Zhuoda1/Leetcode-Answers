class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        int curr = 0;
        while(curr < height.size()){
            while(!st.empty() && height[curr] > height[st.top()]){
                int h = height[st.top()];
                st.pop();
                if(st.empty()) break;
                int dis = curr - st.top() - 1;
                int m = min(height[curr], height[st.top()]);
                ans += dis * (m - h);
            }
            st.push(curr);
            curr++;
        }
        return ans;
    }
};
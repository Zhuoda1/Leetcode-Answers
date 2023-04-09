class Solution {
public:
    int trap(vector<int>& height) {
        // smaller than prev, push
        // higher than prev, pop and count water between them, push new
        stack<int> st;
        int ans = 0;
        st.push(0);
        for(int i = 1; i < height.size(); i++){
            while(!st.empty() && height[i] > height[st.top()]){
                int prev = st.top();
                st.pop();
                if(!st.empty()) ans += (min(height[st.top()], height[i]) - height[prev]) * (i - st.top() - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
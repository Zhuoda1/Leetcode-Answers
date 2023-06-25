class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size,0);
        stack<int> st;
        
        for(int i = size-1; i >= 0; i--){
            // first
            while(st.size() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(!st.empty()) ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};
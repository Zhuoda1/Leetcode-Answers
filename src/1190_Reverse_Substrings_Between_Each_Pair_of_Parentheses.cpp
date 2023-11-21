class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            if(s[i] == '(') st.push(i);
            else if(s[i] == ')'){
                int start = st.top(), end = i - 1;
                st.pop();
                while(start < end) swap(s[start++], s[end--]);
            }
        }
        for(const auto& ch : s) if(ch != '(' && ch != ')') ans.push_back(ch);
        return ans;
    }
};
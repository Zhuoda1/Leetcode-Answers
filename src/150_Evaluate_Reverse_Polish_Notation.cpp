class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string token : tokens){
            if(token.size() == 1 && token[0] < 48){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if(token[0] == '+') st.push(first + second);
                else if(token[0] == '-') st.push(second - first);
                else if(token[0] == '*') st.push(first * second);
                else st.push(int(second / first));
            }
            else st.push(stoi(token));
        }
        return st.top();
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string num = "";
        string cur = "";
        for(const auto& ch : s){
            if(ch == '['){
                st.push({cur, stoi(num)});
                cur = "";
                num = "";
            }
            else if(ch == ']'){
                auto [prev, time] = st.top();
                st.pop();
                for(int i = 0; i < time; i++) prev += cur;
                cur = prev;
            }
            else if(ch >= '0' && ch <= '9') num += ch;
            else cur += ch;
        }
        return cur;
    }
};
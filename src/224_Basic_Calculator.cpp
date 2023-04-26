class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        vector<int> sign(2,1);
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c >= '0'){
                int num = 0;
                while(i < s.size() && s[i] >= '0') num = num * 10 + (s[i++] - '0');
                ans += sign.back() * num;
                sign.pop_back();
                i--;
            }
            else if(c == ')') sign.pop_back();
            else if(c=='(' and s[i+1]=='-'){}
            else if(c != ' '){
                sign.push_back(sign.back() * (c == '-' ? -1 : 1));
            }
        }
        return ans;
    }
};
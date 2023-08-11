class Solution {
public:
    string finalString(string s) {
        string ans = "";
        for(const auto& ch : s){
            if(ch == 'i') reverse(ans.begin(), ans.end());
            else ans.push_back(ch);
        }
        return ans;
    }
};
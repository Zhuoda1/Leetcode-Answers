class Solution {
public:
    int numDecodings(string s) {
        int prev = 1, pp = 0, n = s.size();
        for(int i = n - 1; i >= 0; i--){
            int dig = s[i] == '0' ? 0 : prev;
            if(i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i+1] < '7')) dig += pp;
            pp = prev;
            prev = dig;
        }
        return prev;
    }
};
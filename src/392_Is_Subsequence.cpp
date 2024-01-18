class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int n = s.size(), m = t.size();
        if(n > m) return false;
        else if(n == m) return s == t;
        while(i < n && j < m){
            if(s[i] == t[j]) i++, j++;
            else j++;
        }
        if(i == n) return true;
        else return false;
    }
};
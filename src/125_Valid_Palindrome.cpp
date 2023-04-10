class Solution {
public:
    string cvt(string s){
        string ret = "";
        for(char ch : s){
            if(ch >= '0' && ch <= '9') ret.push_back(ch);
            else if(ch >= 'a' && ch <= 'z') ret.push_back(ch);
            else if(ch >= 'A' && ch <= 'Z') ret.push_back(ch + 32);
            else continue;
        }
        return ret;
    }
    bool isPalindrome(string s) {
        s = cvt(s);
        int len = s.size() - 1;
        int fin = s.size()/2;
        for(int i = 0; i < fin; i++){
            if(s[i] != s[len - i]) return false;
        }
        return true;
    }
};
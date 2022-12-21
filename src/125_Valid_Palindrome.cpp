class Solution {
public:
    bool isPalindrome(string s) {
        s = cvt(s);
        int left, right;
        if(s.size() % 2 == 0){
            left = s.size() / 2 - 1;
            right = s.size() / 2;
        }
        else{
            left = s.size() / 2;
            right = s.size() / 2;
        }
        while(left >= 0 && right < s.size()) if(s[left--] != s[right++]) return false;
        return true;
    }

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
};
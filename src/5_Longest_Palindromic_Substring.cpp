class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() < 1) return "";
        int start = 0, len = 0;
        for(int i = 0; i < s.size(); i++){
            int len1 = find(s, i, i);
            int len2 = find(s, i, i+1);
            int temp = max(len1, len2);
            if(temp > len){
                start = i - (temp - 1)/ 2;
                len = temp;
            }
        }
        return s.substr(start, len);
    }
    int find(string s, int left, int right){
        int len = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            len = right - left + 1;
            left--;
            right++;
        }
        return len;
    }
};
class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0;
        int len = s.length();
        int left, right;
        for(int i = 0; i < len; i++){
            cnt++;
            left = i, right = i + 1;
            while(left >= 0 && right < len && s[left] == s[right]){
                cnt++;
                left--;
                right++;
            }
            left = i - 1, right = i + 1;
            while(left >= 0 && right < len && s[left] == s[right]){
                cnt++;
                left--;
                right++;
            }
        }
        return cnt;
    }
};
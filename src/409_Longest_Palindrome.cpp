class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int ans = 0, maj = 0;
        for(char ch : s){
            mp[ch] += 1;
        }
        for(auto pr : mp){
            if(pr.second % 2 == 0) ans += pr.second;
            else{
                ans += pr.second - 1;
                maj = 1;
            }
        }
        ans += maj;
        return ans;
    }
};
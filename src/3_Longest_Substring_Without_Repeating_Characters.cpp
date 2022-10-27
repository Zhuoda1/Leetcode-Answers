class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int left = 0, right = 0;
        while(right < s.size()){
            mp[s[right]] += 1;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};
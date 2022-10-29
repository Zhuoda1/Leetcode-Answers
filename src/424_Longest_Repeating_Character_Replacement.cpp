class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length() < 2) return s.length();
        int left = 0, right = 0;
        int maxCount = 0, ans = 0;
        vector<int> freq(26,0);

        while(right < s.size()){
            maxCount = max(maxCount, ++freq[s[right++] - 'A']);

            if(right - left > maxCount + k){
                freq[s[left++] - 'A']--;
            }

            ans = max(ans, right - left);
        }

        return ans;
    }
};
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        unordered_map<char, int> mp1;
        for(char ch : s1) mp1[ch] += 1;
        int len = s1.size();
        int diff = len;

        for(int i = 0; i < len; i++){
            if(mp1[s2[i]] > 0) diff--;
            mp1[s2[i]] -= 1;
        }
        if(diff == 0) return true;

        for(int i = len; i < s2.size(); i++){
            if(mp1[s2[i]] > 0) diff--;
            mp1[s2[i]] -= 1;
            mp1[s2[i - len]] += 1;
            if(mp1[s2[i - len]] > 0) diff++;
            if(diff == 0) return true;
        }
        return false;
    }
};
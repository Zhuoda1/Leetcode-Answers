class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(char let : magazine){
            mp[let] += 1;
        }
        for(char let : ransomNote){
            mp[let] -= 1;
            if(mp[let] < 0) return false;
        }
        return true;
    }
};
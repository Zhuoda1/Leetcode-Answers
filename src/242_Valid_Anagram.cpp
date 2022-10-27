class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mp;
        for(char ch : s){
            mp[ch - 'a'] += 1;
        }
        for(char ch : t){
            mp[ch - 'a'] -= 1;
            if(mp[ch - 'a'] == 0) mp.erase(ch - 'a');
        }
        return mp.size() == 0;
    }
};
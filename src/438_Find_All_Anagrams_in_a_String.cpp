class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()) return ans;
        int left = 0, k = p.size();
        int right = left + k;
        unordered_map<char, int> mp;
        for(char ch : p) mp[ch] += 1;
        for(int i = 0; i < p.size(); i++) {
            if(mp[s[i]] > 0) k--;
            mp[s[i]]--;
        }
        if(k == 0) ans.push_back(left);
        while(right < s.size()){
            if(mp[s[right]] > 0) k--;
            mp[s[right]]--;
            mp[s[left]]++;
            if(mp[s[left]] > 0) k++;
            left++;
            if(k == 0) ans.push_back(left);
            right++;
        }
        return ans;
    }
};
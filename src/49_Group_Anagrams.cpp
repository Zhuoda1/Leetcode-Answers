class Solution {
public:
    string strSort(string s){
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string str : strs){
            mp[strSort(str)].push_back(str);
        }
        for(auto ele : mp){
            ans.push_back(ele.second);
        }
        return ans;
    }
};
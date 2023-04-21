class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return vector<string>();
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        backTrack(digits, 0, "", mp, ans);
        return ans;
    }
    void backTrack(string digits, int index, string cur, unordered_map<char, string>& mp, vector<string>& ans){
        if(index == digits.size()){
            ans.push_back(cur);
            return;
        }
        for(char ch : mp[digits[index]]){
            cur.push_back(ch);
            backTrack(digits, index + 1, cur, mp, ans);
            cur.pop_back();
        }
    }
};
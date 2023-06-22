class Solution {
public:
    bool isP(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    void backTracking(string s, int index, vector<vector<string>>& ans, vector<string>& cur){
        if(index == s.size()) ans.push_back(cur);
        for(int i = index; i < s.size(); i++){
            if(isP(s, index, i)){
                cur.push_back(s.substr(index, i-index+1));
                backTracking(s, i+1, ans, cur);
                cur.pop_back();
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        backTracking(s, 0, ans, cur);
        return ans;
    }
};
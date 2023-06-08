class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        backTrack(n, "", 0, 0);
        return ans;
    }
    void backTrack(int n, string curr, int open, int close){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }
        if(open < n) backTrack(n, curr + "(", open+1, close);
        if(close < open) backTrack(n, curr + ")", open, close+1);
    }
};
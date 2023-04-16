class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi = -1;
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1) cnt++;
            }
            if(cnt > maxi){
                maxi = cnt;
                ans = {i, cnt};
            }
        }
        return ans;
    }
};
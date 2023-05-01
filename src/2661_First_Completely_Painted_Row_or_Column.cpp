class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> row(m,n);
        vector<int> col(n,m);
        unordered_map<int, pair<int,int>> mp;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                mp[mat[i][j]] = {i,j};
            }
        }
        for(int i = 0; i < arr.size(); i++){
            if(--row[mp[arr[i]].first] == 0) return i;
            if(--col[mp[arr[i]].second] == 0) return i;
        }
        return -1;
    }
};
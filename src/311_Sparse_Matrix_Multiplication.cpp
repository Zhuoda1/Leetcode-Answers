class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size(), k = mat2.size(), n = mat2[0].size();
        vector<vector<int>> ans;
        for (const auto &row : mat1) {
            vector<int> result(n, 0);
            for (int i = 0; i < k; ++i) {
                if (row[i] == 0) continue;
                for (int j = 0; j < n; ++j) {
                    result[j] += row[i] * mat2[i][j];
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};
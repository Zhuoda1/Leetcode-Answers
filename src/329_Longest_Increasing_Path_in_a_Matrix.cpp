class Solution {
public:
    int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dis(m, vector<int>(n,-1));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                dfs(matrix, i, j, dis);
                ans = max(ans, dis[i][j]);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& dis){
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0; i < 4; i++){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n || matrix[nx][ny] == -1 || matrix[x][y] >= matrix[nx][ny]) continue;
            if(dis[nx][ny] != -1) dis[x][y] = max(dis[x][y], dis[nx][ny] + 1);
            else {
                dfs(matrix, nx, ny, dis);
                dis[x][y] = max(dis[x][y], dis[nx][ny] + 1);
            }
        }
        if(dis[x][y] == -1) dis[x][y] = 1;
        return;
    }
};
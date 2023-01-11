class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0') continue;
                cnt++;
                grid[i][j] = '0';
                q.push({i,j});
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for(int p = 0; p < 4; p++){
                        int nx = x + dir[p][0];
                        int ny = y + dir[p][1];
                        if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
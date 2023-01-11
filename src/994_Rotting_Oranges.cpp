class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = -1;
        int fresh = 0;
        queue<pair<int,int>> q;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }
        if(fresh == 0) return 0;
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int len = q.size();
            time++;
            while(len-- > 0){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int p = 0; p < 4; p++){
                    int nx = x + dir[p][0];
                    int ny = y + dir[p][1];
                    if(nx >= 0 && ny >=0 && nx < m && ny < n && grid[nx][ny] == 1){
                        fresh--;
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        if(fresh > 0) return -1;
        else return time;
    }
};
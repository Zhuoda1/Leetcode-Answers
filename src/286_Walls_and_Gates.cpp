class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        int m = rooms.size();
        int n = rooms[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0) q.push({i,j});
            }
        }
        int dir[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
        int round = 0;
        while(q.size()){
            int len = q.size();
            for(int i = 0; i < len; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && rooms[nx][ny] == 2147483647){
                        rooms[nx][ny] = rooms[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            round++;
        }
    }
};
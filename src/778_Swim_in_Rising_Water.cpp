class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        int n = grid.size();
        int dir[5] = {-1,0,1,0,-1};
        vector<vector<int>>vis(n, vector<int>(n, 0));
        vis[0][0] = 1;
        q.push({grid[0][0],{0,0}});
        while(!q.empty()) {
            int tm = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();
            if(x == n-1 && y == n-1) return tm;
            for(int i=0;i<4;i++) {
                int x1 = x + dir[i];
                int y1 = y + dir[i+1];
                if(x1>=0 && y1>=0 && x1<n && y1<n) {
                    if(vis[x1][y1]) continue;
                    vis[x1][y1] = 1;
                    q.push({max(tm, grid[x1][y1]), {x1, y1}});
                }
            }
        }
        return -1;
    }
};
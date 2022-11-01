struct Dist{
    int x, y, z;
    Dist(int _x, int _y, int _z): x(_x), y(_y), z(_z) {}
    bool operator < (const Dist& that) const {
        return z > that.z;
    }
};
class Solution {
private:
    int dirc[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<int> dist(m * n, INT_MAX);
        vector<int> visit(m * n, 0);
        priority_queue<Dist> q;
        q.emplace(0, 0, 0);
        dist[0] = 0;

        while(!q.empty()){
            auto [x, y, z] = q.top();
            q.pop();
            if(visit[x * n + y]) continue;

            visit[x * n + y] = 1;
            dist[x * n + y] = z;
            for(int i = 0; i < 4; i++){
                int nx = x + dirc[i][0];
                int ny = y + dirc[i][1];
                if(nx >= 0 && ny >=0 && nx < m && ny < n && !visit[nx * n + ny]){
                    q.emplace(nx, ny, max(z, abs(heights[nx][ny] - heights[x][y])));
                }
            }
        }

        return dist[m * n - 1];
    }
};
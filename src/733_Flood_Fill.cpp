class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        int m = image.size(), n = image[0].size();
        vector<vector<int>> curr{};
        vector<vector<int>> next{};
        vector<vector<int>> visit(m, vector<int>(n,0));
        curr.push_back({sr,sc});
        while(curr.size()){
            for(auto pt : curr){
                visit[pt[0]][pt[1]] = 1;
                for(int i = 0; i < 4; i++){
                    int nr = pt[0] + dir[i][0];
                    int nc = pt[1] + dir[i][1];
                    if(nr >= 0 && nc >= 0 && nr < m && nc < n && image[nr][nc] == image[pt[0]][pt[1]] && !visit[nr][nc])
                        next.push_back({nr,nc});
                }
                image[pt[0]][pt[1]] = color;
            }
            curr.clear();
            curr.swap(next);
        }
        return image;
    }
};
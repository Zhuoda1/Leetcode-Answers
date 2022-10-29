class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    ans++;
                    grid[i][j] = '0';
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int row = q.front().first;
                        int column = q.front().second;
                        q.pop();
                        if(column >= 1 && grid[row][column-1] == '1'){
                            q.push({row,column-1});
                            grid[row][column-1] = '0';
                        }
                        if(row >= 1 && grid[row-1][column] == '1'){
                            q.push({row-1,column});
                            grid[row-1][column] = '0';
                        }
                        if(column < grid[0].size() - 1 && grid[row][column+1] == '1'){
                            q.push({row,column+1});
                            grid[row][column+1] = '0';
                        }
                        if(row < grid.size() - 1 && grid[row+1][column] == '1'){
                            q.push({row+1,column});
                            grid[row+1][column] = '0';
                        }
                    }
                }
            }
        }

        return ans;
    }
};
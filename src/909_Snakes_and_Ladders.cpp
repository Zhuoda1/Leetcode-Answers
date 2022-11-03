class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        if(!board.size() || !board[0].size()) return 0;

        queue<int> q;
        unordered_map<int,int> m;
        vector<int> line(1,0);
        int n = board.size();

        bool right = true;
        for(int i = n - 1; i >= 0; i--){
            if(right) for(int j = 0; j < n; j++) line.push_back(board[i][j]);
            else for(int j = n - 1; j >= 0; j--) line.push_back(board[i][j]);
            right = !right;
        }

        q.push(1);
        m[1] = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int step = m[curr];

            if(curr == n * n) return step;

            for(int i = 1; i <= 6; i++){
                int next = curr + i;
                if(next < 0 || next > n * n) continue;

                if(line[next] != -1) next = line[next];

                if(m.count(next) > 0) continue;

                q.push(next);
                m[next] = step + 1;
            }
        }
        return -1;
    }
};
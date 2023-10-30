class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> mp(n,0);
        queue<int> q;
        q.push(0);
        mp[0] = 1;
        while(q.size()){
            while(q.size()){
                int cur = q.front();
                q.pop();
                for(int adj : graph[cur]){
                    if(mp[adj] == 0){
                        mp[adj] = (mp[cur] == 1) ? 2 : 1;
                        q.push(adj);
                    }
                    else if(mp[adj] != mp[cur]) continue;
                    else return false;
                }
            }
            for(int i = 0; i < n; i++){
                if(mp[i] == 0){
                    q.push(i);
                    mp[i] = 1;
                    break;
                }
            }
        }
        return true;
    }
};
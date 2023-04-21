class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};

        queue<int> q;
        vector<vector<int>> adj(n, vector<int>());
        vector<int> deg(n, 0);
        for(auto line : edges){
            adj[line[0]].push_back(line[1]);
            adj[line[1]].push_back(line[0]);
            deg[line[0]]++;
            deg[line[1]]++;
        }
        for(int i = 0; i < deg.size(); i++){
            if(deg[i] == 1) q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int size = q.size();
            ans.clear();
            for(int i = 0; i < size; i++){
                int cur = q.front();
                q.pop();
                ans.push_back(cur);
                for(int adjNode : adj[cur]){
                    if(--deg[adjNode] == 1) q.push(adjNode);
                }
            }
        }
        return ans;
    }
};
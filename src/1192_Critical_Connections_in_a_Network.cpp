class Solution {
public:
    vector<vector<int>> m;
    vector<vector<int>> ans;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        m.resize(n);
        vector<int> ids(n,-1);
        for(auto conn : connections){
            m[conn[0]].push_back(conn[1]);
            m[conn[1]].push_back(conn[0]);
        }
        dfs(0, -1, 0, ids);
        return ans;
    }
    int dfs(int node, int par, int _id, vector<int>& ids){
        ids[node] = _id;

        for(int neighbor : m[node]){
            if(neighbor == par) continue;
            else if(ids[neighbor] == -1){
                ids[node] = min(ids[node], dfs(neighbor, node, _id + 1, ids));
            }
            else{
                ids[node] = min(ids[node], ids[neighbor]);
            }
        }

        if(ids[node] == _id && node != 0){
            ans.push_back({par,node});
        }

        return ids[node];
    }
};
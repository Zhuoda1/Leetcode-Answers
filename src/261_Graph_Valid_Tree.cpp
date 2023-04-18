class Solution {
public:
    int find(vector<int>& parent, int f){
        if(parent[f] != f){
            parent[f] = find(parent, parent[f]);
        }
        return parent[f];
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parent(n,0);
        for(int i = 0; i < n; i++) parent[i] = i;
        for(vector<int> edge : edges){
            int sf = find(parent, edge[0]);
            int bf = find(parent, edge[1]);
            if(sf == bf) return false;
            int sm = min(sf,bf);
            int bi = max(sf,bf);
            parent[bi] = sm;
        }
        for(int i = 0; i < n; i++){
            if(find(parent, i) != 0) return false;
        }
        return true;
    }
};
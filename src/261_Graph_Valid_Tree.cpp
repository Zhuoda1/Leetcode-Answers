class Solution {
public:
    int find(vector<int>& p, int x){
        return p[x] == x ? x : p[x] = find(p, p[x]);
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        vector<int> parents(n, -1);
        for(int i = 0; i < n; i++) parents[i] = i;
        for(auto& edge : edges){
            int fx = find(parents, edge[0]);
            int fy = find(parents, edge[1]);
            if(fx == fy) return false;
            parents[fx] = fy;
        }
        return true;
    }
};
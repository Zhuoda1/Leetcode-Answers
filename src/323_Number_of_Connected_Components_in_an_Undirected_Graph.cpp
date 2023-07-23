class Solution {
public:
    int find(vector<int>& parents, int x){
        if(parents[x] != x) parents[x] = find(parents, parents[x]);
        return parents[x];
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n, -1);
        for(int i = 0; i < n; i++) parents[i] = i;
        for(auto& edge : edges){
            int fx = find(parents, edge[0]);
            int fy = find(parents, edge[1]);
            if(fx < fy) parents[fy] = fx;
            else parents[fx] = fy;
        }
        unordered_set<int> st;
        for(int& val : parents) st.insert(find(parents, val));
        return st.size();
    }
};
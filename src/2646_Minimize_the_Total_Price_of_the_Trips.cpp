class Solution {
public:
    vector<int> dem;
    int count(int start, int end, vector<vector<int>>& adj, int bef){
        if(start == end){
            dem[start]++;
            return 1;
        }
        for(int adjNode : adj[start]){
            if(adjNode == bef) continue;
            if(count(adjNode, end, adj, start)){
                dem[start]++;
                return 1;
            }
        }
        return 0;
    }
    pair<int,int> findPath(int start, vector<vector<int>>& adj, vector<int>& price, int bef){
        int use = price[start] / 2 * dem[start];
        int notUse = price[start] * dem[start];

        for(int adjNode : adj[start]){
            if(adjNode == bef) continue;
            pair<int,int> temp = findPath(adjNode, adj, price, start);

            use += temp.second;
            notUse += min(temp.first, temp.second);
        }
        return {use, notUse};
    }
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> adj(n,vector<int>());
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        dem = vector<int>(n,0);

        for(auto trip : trips){
            count(trip[0], trip[1], adj, -1);
        }
        pair<int,int> ans = findPath(0, adj, price, -1);
        return min(ans.first, ans.second);
    }
};
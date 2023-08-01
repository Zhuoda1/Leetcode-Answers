class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dis(n, 1e8);
        dis[src] = 0;
        for(int i = 0; i <= k; i++){
            vector<int> cur(dis);
            for(const auto& f : flights) cur[f[1]] = min(cur[f[1]], dis[f[0]] + f[2]);
            dis = cur;
        }
        return dis[dst] == 1e8 ? -1 : dis[dst];
    }
};
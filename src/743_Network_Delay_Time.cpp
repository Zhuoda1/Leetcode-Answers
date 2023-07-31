class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(const auto& time : times) adj[time[0]].push_back({time[1], time[2]});
        vector<int> dis(n+1, INT_MAX);
        dis[0] = 0;
        dis[k] = 0;
        vector<int> visit(n+1, 0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});
        while(pq.size()){
            auto cur = pq.top();
            pq.pop();
            if(visit[cur.second]) continue;
            visit[cur.second] = 1;
            for(auto pr : adj[cur.second]){
                if(pr.second + cur.first < dis[pr.first]){
                    dis[pr.first] = pr.second + cur.first;
                    pq.push({dis[pr.first], pr.first});
                }
            }
        }
        int ans = *max_element(dis.begin(), dis.end());
        return ans == INT_MAX ? -1 : ans;
    }
};